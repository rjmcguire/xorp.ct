/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/bgp_base.cc,v 1.15 2002/12/04 23:13:09 atanu Exp $"


#include "bgp_base.hh"

const XrlCmdError
XrlBgpTargetBase::handle_common_0_1_get_target_name(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%d != 0) handling common/0.1/get_target_name", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string name; 
    try {
	XrlCmdError e = common_0_1_get_target_name(
	    name);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for common/0.1/get_target_name failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("name", name);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_common_0_1_get_version(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%d != 0) handling common/0.1/get_version", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string version; 
    try {
	XrlCmdError e = common_0_1_get_version(
	    version);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for common/0.1/get_version failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("version", version);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_local_config(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 2) { 
	XLOG_ERROR("Wrong number of arguments (%d != 2) handling bgp/0.2/local_config", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_local_config(
	    xrl.const_args().get_uint32("as"), 
	    xrl.const_args().get_ipv4("id"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/local_config failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_set_local_as(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%d != 1) handling bgp/0.2/set_local_as", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_set_local_as(
	    xrl.const_args().get_uint32("as"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/set_local_as failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_set_bgpid(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%d != 1) handling bgp/0.2/set_bgpid", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_set_bgpid(
	    xrl.const_args().get_ipv4("id"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/set_bgpid failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_add_peer(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 7) { 
	XLOG_ERROR("Wrong number of arguments (%d != 7) handling bgp/0.2/add_peer", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_add_peer(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    xrl.const_args().get_uint32("as"), 
	    xrl.const_args().get_ipv4("next_hop"), 
	    xrl.const_args().get_uint32("holdtime"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/add_peer failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_delete_peer(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 5) { 
	XLOG_ERROR("Wrong number of arguments (%d != 5) handling bgp/0.2/delete_peer", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_delete_peer(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    xrl.const_args().get_uint32("as"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/delete_peer failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_enable_peer(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%d != 4) handling bgp/0.2/enable_peer", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_enable_peer(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/enable_peer failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_disable_peer(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%d != 4) handling bgp/0.2/disable_peer", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_disable_peer(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/disable_peer failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_set_peer_state(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 5) { 
	XLOG_ERROR("Wrong number of arguments (%d != 5) handling bgp/0.2/set_peer_state", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_set_peer_state(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    xrl.const_args().get_bool("toggle"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/set_peer_state failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_register_rib(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%d != 1) handling bgp/0.2/register_rib", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_register_rib(
	    xrl.const_args().get_string("name"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/register_rib failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_add_route(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%d != 4) handling bgp/0.2/add_route", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_add_route(
	    xrl.const_args().get_int32("origin"), 
	    xrl.const_args().get_int32("asnum"), 
	    xrl.const_args().get_ipv4("next_hop"), 
	    xrl.const_args().get_ipv4net("nlri"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/add_route failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_delete_route(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%d != 1) handling bgp/0.2/delete_route", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_delete_route(
	    xrl.const_args().get_ipv4net("nlri"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/delete_route failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_terminate(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%d != 0) handling bgp/0.2/terminate", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_terminate();
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/terminate failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_set_parameter(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 5) { 
	XLOG_ERROR("Wrong number of arguments (%d != 5) handling bgp/0.2/set_parameter", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_set_parameter(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    xrl.const_args().get_string("parameter"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/set_parameter failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_rib_client_0_1_route_info_changed4(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%d != 4) handling rib_client/0.1/route_info_changed4", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_changed4(
	    xrl.const_args().get_ipv4("addr"), 
	    xrl.const_args().get_uint32("prefix_len"), 
	    xrl.const_args().get_ipv4("nexthop"), 
	    xrl.const_args().get_uint32("metric"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for rib_client/0.1/route_info_changed4 failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_rib_client_0_1_route_info_changed6(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%d != 4) handling rib_client/0.1/route_info_changed6", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_changed6(
	    xrl.const_args().get_ipv6("addr"), 
	    xrl.const_args().get_uint32("prefix_len"), 
	    xrl.const_args().get_ipv6("nexthop"), 
	    xrl.const_args().get_uint32("metric"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for rib_client/0.1/route_info_changed6 failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_rib_client_0_1_route_info_invalid4(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 2) { 
	XLOG_ERROR("Wrong number of arguments (%d != 2) handling rib_client/0.1/route_info_invalid4", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_invalid4(
	    xrl.const_args().get_ipv4("addr"), 
	    xrl.const_args().get_uint32("prefix_len"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for rib_client/0.1/route_info_invalid4 failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_rib_client_0_1_route_info_invalid6(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 2) { 
	XLOG_ERROR("Wrong number of arguments (%d != 2) handling rib_client/0.1/route_info_invalid6", xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_invalid6(
	    xrl.const_args().get_ipv6("addr"), 
	    xrl.const_args().get_uint32("prefix_len"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for rib_client/0.1/route_info_invalid6 failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

