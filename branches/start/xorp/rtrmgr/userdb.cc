// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001,2002 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/rtrmgr/userdb.cc,v 1.8 2002/12/09 18:29:40 hodson Exp $"

#include <sys/types.h>
#include <grp.h>
#include "rtrmgr_module.h"
#include "libxorp/xorp.h"
#include "config.h"
#include "userdb.hh"
#include <sys/types.h>
#include <pwd.h>

User::User(uint32_t user_id, const string& username) {
    _user_id = user_id;
    _username = username;
}

bool 
User::has_acl_capability(const string& capname) const {
    set <string>::iterator i;
    i = _capabilities.find(capname);
    if (i == _capabilities.end()) {
	return false;
    } else {
	return true;
    }
}

void 
User::add_acl_capability(const string& capname) {
    set <string>::iterator i;
    i = _capabilities.find(capname);
    if (i == _capabilities.end()) {
	_capabilities.insert(capname);
    }
}

UserInstance::UserInstance(uint32_t user_id, const string& username) 
    : User(user_id, username) {
}


UserDB::UserDB() {
}

UserDB::~UserDB() {
    map <uint32_t, User*>::iterator i;
    for (i=_users.begin(); i!=_users.end(); i++) {
	delete i->second;
    }
}

void 
UserDB::load_password_file() {
    struct passwd *pwent;
    pwent = getpwent();
    while (pwent != NULL) {
#ifdef DEBUG_USERDB
	printf("User: %s UID: %u\n", pwent->pw_name, pwent->pw_uid);
#endif
	add_user(pwent->pw_uid, pwent->pw_name);
	pwent = getpwent();
    }
    endpwent();
}

User* 
UserDB::add_user(uint32_t user_id, const string& username) {
    if (_users.find(user_id) == _users.end()) {
	User *newuser = new User(user_id, username);
	struct group *grp = getgrnam("xorp");
	if (grp != NULL) {
	    char **gr_mem = grp->gr_mem;
	    while (*gr_mem != NULL) {
#ifdef DEBUG_USERDB
		printf("found user %s in group xorp\n", *gr_mem);
#endif
		if (*gr_mem == username) {
		    newuser->add_acl_capability("config");
		    break;
		}
		gr_mem++;
	    }
	}
	_users[user_id] = newuser;
	return newuser;
    } else {
	//user id already exists
	return NULL;
    }
}

const User* 
UserDB::find_user_by_user_id(uint32_t user_id) const {
    map <uint32_t,User*>::const_iterator i = _users.find(user_id);
    if (i == _users.end())
	return NULL;
    else
	return i->second;
}


void 
UserDB::remove_user(uint32_t user_id) {
    map <uint32_t,User*>::iterator i = _users.find(user_id);
    User *user = i->second;
    _users.erase(i);
    delete user;
}

bool
UserDB::has_capability(uint32_t user_id, const string& capability) const {
    const User* user = find_user_by_user_id(user_id);
    if (user == NULL) 
	return false;
    return (user->has_acl_capability(capability));
}
