/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/test_xif.hh,v 1.9 2002/11/19 19:31:47 hodson Exp $
 */


#ifndef __XRL_INTERFACES_TEST_XIF_HH__
#define __XRL_INTERFACES_TEST_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifTest"
#include "libxorp/xlog.h"
#include "libxipc/xrlrouter.hh"

class XrlTestV1p0Client {
public:
    XrlTestV1p0Client(XrlRouter* r) : _router(r) {}
    virtual ~XrlTestV1p0Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB0;
    /**
     *  Send Xrl intended to:
     *  
     *  Print hello world
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_print_hello_world(
	const char*	target_name, 
	const CB0&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB1;
    /**
     *  Send Xrl intended to:
     *  
     *  Print "hello world" and a user supplied greeting.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param msg greeting to be printed.
     */
    bool send_print_hello_world_and_message(
	const char*	target_name, 
	const string&	msg, 
	const CB1&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const int32_t*>::RefPtr CB2;
    /**
     *  Send Xrl intended to:
     *  
     *  Count number of greetings available
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_get_greeting_count(
	const char*	target_name, 
	const CB2&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr CB3;
    /**
     *  Send Xrl intended to:
     *  
     *  Get greeting
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param greeting_num index of greeting
     */
    bool send_get_greeting(
	const char*	target_name, 
	const int32_t&	greeting_num, 
	const CB3&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB4;
    /**
     *  Send Xrl intended to:
     *  
     *  Something that always fails.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_shoot_foot(
	const char*	target_name, 
	const CB4&	cb
    );

protected:
    XrlRouter* _router;

private:
    void unmarshall0(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB0		cb
    );

    void unmarshall1(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB1		cb
    );

    void unmarshall2(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB2		cb
    );

    void unmarshall3(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB3		cb
    );

    void unmarshall4(
	const XrlError&	e, 
	XrlRouter&	/* r */, 
	const Xrl&	/* x */, 
	XrlArgs*	a, 
	CB4		cb
    );

};

#endif /* __XRL_INTERFACES_TEST_XIF_HH__ */
