/*
 * Copyright (c) 2001-2007 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/fea_ifmgr_mirror_xif.hh,v 1.12 2006/03/26 22:39:20 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_FEA_IFMGR_MIRROR_XIF_HH__
#define __XRL_INTERFACES_FEA_IFMGR_MIRROR_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFeaIfmgrMirror"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlFeaIfmgrMirrorV0p1Client {
public:
    XrlFeaIfmgrMirrorV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlFeaIfmgrMirrorV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceAddCB;

    bool send_interface_add(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const InterfaceAddCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceRemoveCB;

    bool send_interface_remove(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const InterfaceRemoveCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetEnabledCB;

    bool send_interface_set_enabled(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const bool&	enabled,
	const InterfaceSetEnabledCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetDiscardCB;

    bool send_interface_set_discard(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const bool&	discard,
	const InterfaceSetDiscardCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetMtuCB;

    bool send_interface_set_mtu(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const uint32_t&	mtu_bytes,
	const InterfaceSetMtuCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetMacCB;

    bool send_interface_set_mac(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const Mac&	mac,
	const InterfaceSetMacCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetPifIndexCB;

    bool send_interface_set_pif_index(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const uint32_t&	index,
	const InterfaceSetPifIndexCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetNoCarrierCB;

    bool send_interface_set_no_carrier(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const bool&	no_carrier,
	const InterfaceSetNoCarrierCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VifAddCB;

    bool send_vif_add(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const VifAddCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VifRemoveCB;

    bool send_vif_remove(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const VifRemoveCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VifSetEnabledCB;

    bool send_vif_set_enabled(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const bool&	enabled,
	const VifSetEnabledCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VifSetMulticastCapableCB;

    bool send_vif_set_multicast_capable(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const bool&	capable,
	const VifSetMulticastCapableCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VifSetBroadcastCapableCB;

    bool send_vif_set_broadcast_capable(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const bool&	capable,
	const VifSetBroadcastCapableCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VifSetP2PCapableCB;

    bool send_vif_set_p2p_capable(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const bool&	capable,
	const VifSetP2PCapableCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VifSetLoopbackCB;

    bool send_vif_set_loopback(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const bool&	loopback,
	const VifSetLoopbackCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VifSetPifIndexCB;

    bool send_vif_set_pif_index(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	index,
	const VifSetPifIndexCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv4AddCB;

    bool send_ipv4_add(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const Ipv4AddCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv4RemoveCB;

    bool send_ipv4_remove(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const Ipv4RemoveCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv4SetPrefixCB;

    bool send_ipv4_set_prefix(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	prefix_len,
	const Ipv4SetPrefixCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv4SetEnabledCB;

    bool send_ipv4_set_enabled(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const bool&	enabled,
	const Ipv4SetEnabledCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv4SetMulticastCapableCB;

    bool send_ipv4_set_multicast_capable(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const bool&	capable,
	const Ipv4SetMulticastCapableCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv4SetLoopbackCB;

    bool send_ipv4_set_loopback(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const bool&	loopback,
	const Ipv4SetLoopbackCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv4SetBroadcastCB;

    bool send_ipv4_set_broadcast(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const IPv4&	oaddr,
	const Ipv4SetBroadcastCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv4SetEndpointCB;

    bool send_ipv4_set_endpoint(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const IPv4&	oaddr,
	const Ipv4SetEndpointCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv6AddCB;

    bool send_ipv6_add(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const Ipv6AddCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv6RemoveCB;

    bool send_ipv6_remove(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const Ipv6RemoveCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv6SetPrefixCB;

    bool send_ipv6_set_prefix(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	prefix_len,
	const Ipv6SetPrefixCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv6SetEnabledCB;

    bool send_ipv6_set_enabled(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const bool&	enabled,
	const Ipv6SetEnabledCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv6SetLoopbackCB;

    bool send_ipv6_set_loopback(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const bool&	loopback,
	const Ipv6SetLoopbackCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv6SetMulticastCapableCB;

    bool send_ipv6_set_multicast_capable(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const bool&	capable,
	const Ipv6SetMulticastCapableCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr Ipv6SetEndpointCB;

    bool send_ipv6_set_endpoint(
	const char*	dst_xrl_target_name,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const IPv6&	oaddr,
	const Ipv6SetEndpointCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr HintTreeCompleteCB;

    bool send_hint_tree_complete(
	const char*	dst_xrl_target_name,
	const HintTreeCompleteCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr HintUpdatesMadeCB;

    bool send_hint_updates_made(
	const char*	dst_xrl_target_name,
	const HintUpdatesMadeCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_interface_add(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceAddCB		cb
    );

    void unmarshall_interface_remove(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceRemoveCB		cb
    );

    void unmarshall_interface_set_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetEnabledCB		cb
    );

    void unmarshall_interface_set_discard(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetDiscardCB		cb
    );

    void unmarshall_interface_set_mtu(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetMtuCB		cb
    );

    void unmarshall_interface_set_mac(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetMacCB		cb
    );

    void unmarshall_interface_set_pif_index(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetPifIndexCB		cb
    );

    void unmarshall_interface_set_no_carrier(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetNoCarrierCB		cb
    );

    void unmarshall_vif_add(
	const XrlError&	e,
	XrlArgs*	a,
	VifAddCB		cb
    );

    void unmarshall_vif_remove(
	const XrlError&	e,
	XrlArgs*	a,
	VifRemoveCB		cb
    );

    void unmarshall_vif_set_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	VifSetEnabledCB		cb
    );

    void unmarshall_vif_set_multicast_capable(
	const XrlError&	e,
	XrlArgs*	a,
	VifSetMulticastCapableCB		cb
    );

    void unmarshall_vif_set_broadcast_capable(
	const XrlError&	e,
	XrlArgs*	a,
	VifSetBroadcastCapableCB		cb
    );

    void unmarshall_vif_set_p2p_capable(
	const XrlError&	e,
	XrlArgs*	a,
	VifSetP2PCapableCB		cb
    );

    void unmarshall_vif_set_loopback(
	const XrlError&	e,
	XrlArgs*	a,
	VifSetLoopbackCB		cb
    );

    void unmarshall_vif_set_pif_index(
	const XrlError&	e,
	XrlArgs*	a,
	VifSetPifIndexCB		cb
    );

    void unmarshall_ipv4_add(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv4AddCB		cb
    );

    void unmarshall_ipv4_remove(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv4RemoveCB		cb
    );

    void unmarshall_ipv4_set_prefix(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv4SetPrefixCB		cb
    );

    void unmarshall_ipv4_set_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv4SetEnabledCB		cb
    );

    void unmarshall_ipv4_set_multicast_capable(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv4SetMulticastCapableCB		cb
    );

    void unmarshall_ipv4_set_loopback(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv4SetLoopbackCB		cb
    );

    void unmarshall_ipv4_set_broadcast(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv4SetBroadcastCB		cb
    );

    void unmarshall_ipv4_set_endpoint(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv4SetEndpointCB		cb
    );

    void unmarshall_ipv6_add(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv6AddCB		cb
    );

    void unmarshall_ipv6_remove(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv6RemoveCB		cb
    );

    void unmarshall_ipv6_set_prefix(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv6SetPrefixCB		cb
    );

    void unmarshall_ipv6_set_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv6SetEnabledCB		cb
    );

    void unmarshall_ipv6_set_loopback(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv6SetLoopbackCB		cb
    );

    void unmarshall_ipv6_set_multicast_capable(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv6SetMulticastCapableCB		cb
    );

    void unmarshall_ipv6_set_endpoint(
	const XrlError&	e,
	XrlArgs*	a,
	Ipv6SetEndpointCB		cb
    );

    void unmarshall_hint_tree_complete(
	const XrlError&	e,
	XrlArgs*	a,
	HintTreeCompleteCB		cb
    );

    void unmarshall_hint_updates_made(
	const XrlError&	e,
	XrlArgs*	a,
	HintUpdatesMadeCB		cb
    );

};

#endif /* __XRL_INTERFACES_FEA_IFMGR_MIRROR_XIF_HH__ */