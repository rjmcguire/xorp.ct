/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/mfea_base.hh,v 1.41 2002/12/08 11:02:39 pavlin Exp $
 */


#ifndef __XRL_INTERFACES_MFEA_BASE_HH__
#define __XRL_INTERFACES_MFEA_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlMfeaTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrlrouter.hh"

class XrlMfeaTargetBase {
protected:
    XrlCmdMap* _router;
    
public:
    XrlMfeaTargetBase(XrlCmdMap* r) : _router(r) { add_handlers(); }
    virtual ~XrlMfeaTargetBase() { remove_handlers(); }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values, 
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values, 
	string&	version) = 0;

    virtual XrlCmdError cli_processor_0_1_process_command(
	// Input values, 
	const string&	processor_name, 
	const string&	cli_term_name, 
	const uint32_t&	cli_session_id, 
	const string&	command_name, 
	const string&	command_args, 
	// Output values, 
	string&	ret_processor_name, 
	string&	ret_cli_term_name, 
	uint32_t&	ret_cli_session_id, 
	string&	ret_command_output) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Add/delete a protocol in the Multicast FEA.
     *  
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *  
     *  @param protocol_name the name of the protocol to add/delete.
     *  
     *  @param protocol_id the ID of the protocol to add/delete (both sides
     *  must agree on the particular values).
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_add_protocol4(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_add_protocol6(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_delete_protocol4(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_delete_protocol6(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Start/stop a protocol on an interface in the Multicast FEA.
     *  
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *  
     *  @param protocol_name the name of the protocol to start/stop on the
     *  particular vif.
     *  
     *  @param protocol_id the ID of the protocol to add/stop on the particular
     *  vif (both sides must agree on the particular values).
     *  
     *  @param vif_name the name of the vif to start/stop for the particular
     *  protocol.
     *  
     *  @param vif_index the index of the vif to start/stop for the particular
     *  protocol.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_start_protocol_vif4(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_start_protocol_vif6(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_stop_protocol_vif4(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_stop_protocol_vif6(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Enable/disable the receiving of kernel-originated signal messages.
     *  
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *  
     *  @param protocol_name the name of the protocol to add.
     *  
     *  @param protocol_id the ID of the protocol to add (both sides must agree
     *  on the particular values).
     *  
     *  @param is_allow if true, enable the receiving of kernel-originated
     *  signal messages by protocol 'protocol_name'.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_allow_signal_messages(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const bool&	is_allow, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Enable/disable the receiving of Multicast Routing Information Base
     *  information.
     *  
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *  
     *  @param protocol_name the name of the protocol to add.
     *  
     *  @param protocol_id the ID of the protocol to add (both sides must agree
     *  on the particular values).
     *  
     *  @param is_allow if true, enable the receiving of MRIB information
     *  messages by protocol 'protocol_name'.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_allow_mrib_messages(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const bool&	is_allow, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Join/leave a multicast group.
     *  
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *  
     *  @param protocol_name the name of the protocol that joins/leave the
     *  group.
     *  
     *  @param protocol_id the ID of the protocol that joins/leave the group
     *  (both sides must agree on the particular values).
     *  
     *  @param vif_name the name of the vif to join/leave the multicast group.
     *  
     *  @param vif_index the index of the vif to join/leave the multicast
     *  group.
     *  
     *  @param group_address the multicast group to join/leave.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_join_multicast_group4(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv4&	group_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_join_multicast_group6(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv6&	group_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_leave_multicast_group4(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv4&	group_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_leave_multicast_group6(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv6&	group_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Add/delete a Multicast Forwarding Cache with the kernel.
     *  
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *  
     *  @param source_address the source address of the MFC to add/delete.
     *  
     *  @param group_address the group address of the MFC to add/delete.
     *  
     *  @param iif_vif_index the index of the vif that is the incoming
     *  interface.
     *  
     *  @param oiflist the bit-vector with the set of outgoing interfaces.
     *  
     *  @param oiflist_disable_wrongvif the bit-vector with the set of outgoing
     *  interfaces to disable WRONGVIF kernel signal.
     *  
     *  @param max_vifs_oiflist the number of vifs covered by oiflist or
     *  oiflist_disable_wrongvif .
     *  
     *  @param rp_address the RP address of the MFC to add.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_add_mfc4(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv4&	source_address, 
	const IPv4&	group_address, 
	const uint32_t&	iif_vif_index, 
	const vector<uint8_t>&	oiflist, 
	const vector<uint8_t>&	oiflist_disable_wrongvif, 
	const uint32_t&	max_vifs_oiflist, 
	const IPv4&	rp_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_add_mfc6(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv6&	source_address, 
	const IPv6&	group_address, 
	const uint32_t&	iif_vif_index, 
	const vector<uint8_t>&	oiflist, 
	const vector<uint8_t>&	oiflist_disable_wrongvif, 
	const uint32_t&	max_vifs_oiflist, 
	const IPv6&	rp_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_delete_mfc4(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv4&	source_address, 
	const IPv4&	group_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_delete_mfc6(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv6&	source_address, 
	const IPv6&	group_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Send a protocol message to the MFEA.
     *  
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *  
     *  @param protocol_name the name of the protocol that sends a message.
     *  
     *  @param protocol_id the ID of the protocol that sends a message (both
     *  sides must agree on the particular values).
     *  
     *  @param vif_name the name of the vif to send the message.
     *  
     *  @param vif_index the vif index of the vif to send the message.
     *  
     *  @param source_address the address of the sender.
     *  
     *  @param dest_address the destination address.
     *  
     *  @param ip_ttl the TTL of the IP packet to send. If it has a negative
     *  value, the TTL will be set by the lower layers.
     *  
     *  @param ip_tos the TOS of the IP packet to send. If it has a negative
     *  value, the TOS will be set by the lower layers.
     *  
     *  @param is_router_alert set/reset the IP Router Alert option in the IP
     *  packet to send (when applicable).
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_send_protocol_message4(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv4&	source_address, 
	const IPv4&	dest_address, 
	const int32_t&	ip_ttl, 
	const int32_t&	ip_tos, 
	const bool&	is_router_alert, 
	const vector<uint8_t>&	protocol_message, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_send_protocol_message6(
	// Input values, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv6&	source_address, 
	const IPv6&	dest_address, 
	const int32_t&	ip_ttl, 
	const int32_t&	ip_tos, 
	const bool&	is_router_alert, 
	const vector<uint8_t>&	protocol_message, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Add/delete a dataflow monitor with the MFEA.
     *  
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *  
     *  @param source_address the source address of the dataflow to start/stop
     *  monitoring.
     *  
     *  @param group_address the group address of the dataflow to start/stop
     *  monitoring.
     *  
     *  @param threshold_interval_sec the number of seconds in the interval to
     *  measure.
     *  
     *  @param threshold_interval_usec the number of microseconds in the
     *  interval to measure.
     *  
     *  @param threshold_packets the threshold (in number of packets) to
     *  compare against.
     *  
     *  @param threshold_bytes the threshold (in number of bytes) to compare
     *  against.
     *  
     *  @param is_threshold_in_packets if true, threshold_packets is valid.
     *  
     *  @param is_threshold_in_bytes if true, threshold_bytes is valid.
     *  
     *  @param is_geq_upcall if true, the operation for comparison is ">=".
     *  
     *  @param is_leq_upcall if true, the operation for comparison is "<=".
     */
    virtual XrlCmdError mfea_0_1_add_dataflow_monitor4(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv4&	source_address, 
	const IPv4&	group_address, 
	const uint32_t&	threshold_interval_sec, 
	const uint32_t&	threshold_interval_usec, 
	const uint32_t&	threshold_packets, 
	const uint32_t&	threshold_bytes, 
	const bool&	is_threshold_in_packets, 
	const bool&	is_threshold_in_bytes, 
	const bool&	is_geq_upcall, 
	const bool&	is_leq_upcall, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_add_dataflow_monitor6(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv6&	source_address, 
	const IPv6&	group_address, 
	const uint32_t&	threshold_interval_sec, 
	const uint32_t&	threshold_interval_usec, 
	const uint32_t&	threshold_packets, 
	const uint32_t&	threshold_bytes, 
	const bool&	is_threshold_in_packets, 
	const bool&	is_threshold_in_bytes, 
	const bool&	is_geq_upcall, 
	const bool&	is_leq_upcall, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_delete_dataflow_monitor4(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv4&	source_address, 
	const IPv4&	group_address, 
	const uint32_t&	threshold_interval_sec, 
	const uint32_t&	threshold_interval_usec, 
	const uint32_t&	threshold_packets, 
	const uint32_t&	threshold_bytes, 
	const bool&	is_threshold_in_packets, 
	const bool&	is_threshold_in_bytes, 
	const bool&	is_geq_upcall, 
	const bool&	is_leq_upcall, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_delete_dataflow_monitor6(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv6&	source_address, 
	const IPv6&	group_address, 
	const uint32_t&	threshold_interval_sec, 
	const uint32_t&	threshold_interval_usec, 
	const uint32_t&	threshold_packets, 
	const uint32_t&	threshold_bytes, 
	const bool&	is_threshold_in_packets, 
	const bool&	is_threshold_in_bytes, 
	const bool&	is_geq_upcall, 
	const bool&	is_leq_upcall, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_delete_all_dataflow_monitor4(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv4&	source_address, 
	const IPv4&	group_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_delete_all_dataflow_monitor6(
	// Input values, 
	const string&	xrl_sender_name, 
	const IPv6&	source_address, 
	const IPv6&	group_address, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Enable/disable/start/stop a MFEA vif interface.
     *  
     *  @param vif_name the name of the vif to enable/disable/start/stop.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_enable_vif(
	// Input values, 
	const string&	vif_name, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_disable_vif(
	// Input values, 
	const string&	vif_name, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_start_vif(
	// Input values, 
	const string&	vif_name, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_stop_vif(
	// Input values, 
	const string&	vif_name, 
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Enable/disable/start/stop all MFEA vif interfaces.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_enable_all_vifs(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_disable_all_vifs(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_start_all_vifs(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_stop_all_vifs(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Enable/disable/start/stop the MFEA and the MFEA CLI access.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_enable_mfea(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_disable_mfea(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_enable_cli(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_disable_cli(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_start_mfea(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_stop_mfea(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_start_cli(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_stop_cli(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *  
     *  Enable/disable the MFEA trace log.
     *  
     *  @param fail true if failure has occured.
     *  
     *  @param reason contains failure reason if it occured.
     */
    virtual XrlCmdError mfea_0_1_enable_log_trace(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

    virtual XrlCmdError mfea_0_1_disable_log_trace(
	// Output values, 
	bool&	fail, 
	string&	reason) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_common_0_1_get_version(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_cli_processor_0_1_process_command(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_add_protocol4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_add_protocol6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_delete_protocol4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_delete_protocol6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_start_protocol_vif4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_start_protocol_vif6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_stop_protocol_vif4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_stop_protocol_vif6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_allow_signal_messages(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_allow_mrib_messages(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_join_multicast_group4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_join_multicast_group6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_leave_multicast_group4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_leave_multicast_group6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_add_mfc4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_add_mfc6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_delete_mfc4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_delete_mfc6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_send_protocol_message4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_send_protocol_message6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_add_dataflow_monitor4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_add_dataflow_monitor6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_delete_dataflow_monitor4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_delete_dataflow_monitor6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_delete_all_dataflow_monitor4(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_delete_all_dataflow_monitor6(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_enable_vif(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_disable_vif(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_start_vif(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_stop_vif(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_enable_all_vifs(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_disable_all_vifs(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_start_all_vifs(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_stop_all_vifs(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_enable_mfea(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_disable_mfea(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_enable_cli(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_disable_cli(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_start_mfea(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_stop_mfea(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_start_cli(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_stop_cli(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_enable_log_trace(const Xrl& x, XrlArgs* a);

    const XrlCmdError handle_mfea_0_1_disable_log_trace(const Xrl& x, XrlArgs* a);

    void add_handlers()
    {
	if (_router->add_handler("common/0.1/get_target_name", 
	    callback(this, &XrlMfeaTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/common/0.1/get_target_name");
	}
	if (_router->add_handler("common/0.1/get_version", 
	    callback(this, &XrlMfeaTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/common/0.1/get_version");
	}
	if (_router->add_handler("cli_processor/0.1/process_command", 
	    callback(this, &XrlMfeaTargetBase::handle_cli_processor_0_1_process_command)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/cli_processor/0.1/process_command");
	}
	if (_router->add_handler("mfea/0.1/add_protocol4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_add_protocol4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/add_protocol4");
	}
	if (_router->add_handler("mfea/0.1/add_protocol6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_add_protocol6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/add_protocol6");
	}
	if (_router->add_handler("mfea/0.1/delete_protocol4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_delete_protocol4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/delete_protocol4");
	}
	if (_router->add_handler("mfea/0.1/delete_protocol6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_delete_protocol6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/delete_protocol6");
	}
	if (_router->add_handler("mfea/0.1/start_protocol_vif4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_start_protocol_vif4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/start_protocol_vif4");
	}
	if (_router->add_handler("mfea/0.1/start_protocol_vif6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_start_protocol_vif6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/start_protocol_vif6");
	}
	if (_router->add_handler("mfea/0.1/stop_protocol_vif4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_stop_protocol_vif4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/stop_protocol_vif4");
	}
	if (_router->add_handler("mfea/0.1/stop_protocol_vif6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_stop_protocol_vif6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/stop_protocol_vif6");
	}
	if (_router->add_handler("mfea/0.1/allow_signal_messages", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_allow_signal_messages)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/allow_signal_messages");
	}
	if (_router->add_handler("mfea/0.1/allow_mrib_messages", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_allow_mrib_messages)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/allow_mrib_messages");
	}
	if (_router->add_handler("mfea/0.1/join_multicast_group4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_join_multicast_group4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/join_multicast_group4");
	}
	if (_router->add_handler("mfea/0.1/join_multicast_group6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_join_multicast_group6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/join_multicast_group6");
	}
	if (_router->add_handler("mfea/0.1/leave_multicast_group4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_leave_multicast_group4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/leave_multicast_group4");
	}
	if (_router->add_handler("mfea/0.1/leave_multicast_group6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_leave_multicast_group6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/leave_multicast_group6");
	}
	if (_router->add_handler("mfea/0.1/add_mfc4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_add_mfc4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/add_mfc4");
	}
	if (_router->add_handler("mfea/0.1/add_mfc6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_add_mfc6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/add_mfc6");
	}
	if (_router->add_handler("mfea/0.1/delete_mfc4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_delete_mfc4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/delete_mfc4");
	}
	if (_router->add_handler("mfea/0.1/delete_mfc6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_delete_mfc6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/delete_mfc6");
	}
	if (_router->add_handler("mfea/0.1/send_protocol_message4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_send_protocol_message4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/send_protocol_message4");
	}
	if (_router->add_handler("mfea/0.1/send_protocol_message6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_send_protocol_message6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/send_protocol_message6");
	}
	if (_router->add_handler("mfea/0.1/add_dataflow_monitor4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_add_dataflow_monitor4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/add_dataflow_monitor4");
	}
	if (_router->add_handler("mfea/0.1/add_dataflow_monitor6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_add_dataflow_monitor6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/add_dataflow_monitor6");
	}
	if (_router->add_handler("mfea/0.1/delete_dataflow_monitor4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_delete_dataflow_monitor4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/delete_dataflow_monitor4");
	}
	if (_router->add_handler("mfea/0.1/delete_dataflow_monitor6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_delete_dataflow_monitor6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/delete_dataflow_monitor6");
	}
	if (_router->add_handler("mfea/0.1/delete_all_dataflow_monitor4", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_delete_all_dataflow_monitor4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/delete_all_dataflow_monitor4");
	}
	if (_router->add_handler("mfea/0.1/delete_all_dataflow_monitor6", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_delete_all_dataflow_monitor6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/delete_all_dataflow_monitor6");
	}
	if (_router->add_handler("mfea/0.1/enable_vif", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_enable_vif)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/enable_vif");
	}
	if (_router->add_handler("mfea/0.1/disable_vif", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_disable_vif)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/disable_vif");
	}
	if (_router->add_handler("mfea/0.1/start_vif", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_start_vif)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/start_vif");
	}
	if (_router->add_handler("mfea/0.1/stop_vif", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_stop_vif)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/stop_vif");
	}
	if (_router->add_handler("mfea/0.1/enable_all_vifs", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_enable_all_vifs)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/enable_all_vifs");
	}
	if (_router->add_handler("mfea/0.1/disable_all_vifs", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_disable_all_vifs)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/disable_all_vifs");
	}
	if (_router->add_handler("mfea/0.1/start_all_vifs", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_start_all_vifs)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/start_all_vifs");
	}
	if (_router->add_handler("mfea/0.1/stop_all_vifs", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_stop_all_vifs)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/stop_all_vifs");
	}
	if (_router->add_handler("mfea/0.1/enable_mfea", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_enable_mfea)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/enable_mfea");
	}
	if (_router->add_handler("mfea/0.1/disable_mfea", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_disable_mfea)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/disable_mfea");
	}
	if (_router->add_handler("mfea/0.1/enable_cli", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_enable_cli)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/enable_cli");
	}
	if (_router->add_handler("mfea/0.1/disable_cli", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_disable_cli)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/disable_cli");
	}
	if (_router->add_handler("mfea/0.1/start_mfea", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_start_mfea)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/start_mfea");
	}
	if (_router->add_handler("mfea/0.1/stop_mfea", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_stop_mfea)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/stop_mfea");
	}
	if (_router->add_handler("mfea/0.1/start_cli", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_start_cli)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/start_cli");
	}
	if (_router->add_handler("mfea/0.1/stop_cli", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_stop_cli)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/stop_cli");
	}
	if (_router->add_handler("mfea/0.1/enable_log_trace", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_enable_log_trace)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/enable_log_trace");
	}
	if (_router->add_handler("mfea/0.1/disable_log_trace", 
	    callback(this, &XrlMfeaTargetBase::handle_mfea_0_1_disable_log_trace)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://mfea/mfea/0.1/disable_log_trace");
	}
    }

    void remove_handlers()
    {
	_router->remove_handler("common/0.1/get_target_name");
	_router->remove_handler("common/0.1/get_version");
	_router->remove_handler("cli_processor/0.1/process_command");
	_router->remove_handler("mfea/0.1/add_protocol4");
	_router->remove_handler("mfea/0.1/add_protocol6");
	_router->remove_handler("mfea/0.1/delete_protocol4");
	_router->remove_handler("mfea/0.1/delete_protocol6");
	_router->remove_handler("mfea/0.1/start_protocol_vif4");
	_router->remove_handler("mfea/0.1/start_protocol_vif6");
	_router->remove_handler("mfea/0.1/stop_protocol_vif4");
	_router->remove_handler("mfea/0.1/stop_protocol_vif6");
	_router->remove_handler("mfea/0.1/allow_signal_messages");
	_router->remove_handler("mfea/0.1/allow_mrib_messages");
	_router->remove_handler("mfea/0.1/join_multicast_group4");
	_router->remove_handler("mfea/0.1/join_multicast_group6");
	_router->remove_handler("mfea/0.1/leave_multicast_group4");
	_router->remove_handler("mfea/0.1/leave_multicast_group6");
	_router->remove_handler("mfea/0.1/add_mfc4");
	_router->remove_handler("mfea/0.1/add_mfc6");
	_router->remove_handler("mfea/0.1/delete_mfc4");
	_router->remove_handler("mfea/0.1/delete_mfc6");
	_router->remove_handler("mfea/0.1/send_protocol_message4");
	_router->remove_handler("mfea/0.1/send_protocol_message6");
	_router->remove_handler("mfea/0.1/add_dataflow_monitor4");
	_router->remove_handler("mfea/0.1/add_dataflow_monitor6");
	_router->remove_handler("mfea/0.1/delete_dataflow_monitor4");
	_router->remove_handler("mfea/0.1/delete_dataflow_monitor6");
	_router->remove_handler("mfea/0.1/delete_all_dataflow_monitor4");
	_router->remove_handler("mfea/0.1/delete_all_dataflow_monitor6");
	_router->remove_handler("mfea/0.1/enable_vif");
	_router->remove_handler("mfea/0.1/disable_vif");
	_router->remove_handler("mfea/0.1/start_vif");
	_router->remove_handler("mfea/0.1/stop_vif");
	_router->remove_handler("mfea/0.1/enable_all_vifs");
	_router->remove_handler("mfea/0.1/disable_all_vifs");
	_router->remove_handler("mfea/0.1/start_all_vifs");
	_router->remove_handler("mfea/0.1/stop_all_vifs");
	_router->remove_handler("mfea/0.1/enable_mfea");
	_router->remove_handler("mfea/0.1/disable_mfea");
	_router->remove_handler("mfea/0.1/enable_cli");
	_router->remove_handler("mfea/0.1/disable_cli");
	_router->remove_handler("mfea/0.1/start_mfea");
	_router->remove_handler("mfea/0.1/stop_mfea");
	_router->remove_handler("mfea/0.1/start_cli");
	_router->remove_handler("mfea/0.1/stop_cli");
	_router->remove_handler("mfea/0.1/enable_log_trace");
	_router->remove_handler("mfea/0.1/disable_log_trace");
    }
};

#endif /* __XRL_INTERFACES_MFEA_BASE_HH__ */
