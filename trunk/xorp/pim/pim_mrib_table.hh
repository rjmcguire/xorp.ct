// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
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

// $XORP: xorp/pim/pim_mrib_table.hh,v 1.2 2003/03/10 23:20:49 hodson Exp $


#ifndef __PIM_PIM_MRIB_TABLE_HH__
#define __PIM_PIM_MRIB_TABLE_HH__


//
// PIM Multicast Routing Information Base Table header file.
//


#include <list>

#include "mrt/timer.hh"
#include "mrt/mrib_table.hh"


//
// Constants definitions
//

//
// Structures/classes, typedefs and macros
//

class IPvXNet;
class PimMrt;
class PimNode;

// PIM-specific Multicast Routing Information Base Table
class PimMribTable : public MribTable {
public:
    PimMribTable(PimNode& pim_node);
    virtual ~PimMribTable();
    
    // Redirection functions (to the pim_node)    
    PimNode&	pim_node() const { return (_pim_node);			}
    int		family();
    PimMrt&	pim_mrt();
    
    void	clear();
    Mrib	*find(const IPvX& address) const;
    
    void	add_pending_insert(uint32_t tid, const Mrib& mrib);
    void	add_pending_remove(uint32_t tid, const Mrib& mrib);
    void	commit_pending_transactions(uint32_t tid);
    
    void	apply_mrib_changes();
    
    list<IPvXNet>& modified_prefix_list() { return (_modified_prefix_list); }
    
private:
    PimNode&	_pim_node;	// The PIM node
    
    /**
     * Add/merge a modified prefix to the '_modified_prefix_list'.
     */
    void	add_modified_prefix(const IPvXNet& new_addr_prefix);
    
    // The merged and enlarged list of modified prefixes that need
    // to be applied to the PimMrt.
    list<IPvXNet> _modified_prefix_list;
};

//
// Global variables
//

//
// Global functions prototypes
//

#endif // __PIM_PIM_MRIB_TABLE_HH__
