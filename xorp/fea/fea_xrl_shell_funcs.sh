#!/bin/sh

# Conditionally set ${srcdir} if it wasn't assigned (e.g., by `gmake check`)
if [ "X${srcdir}" = "X" ] ; then srcdir=`dirname $0` ; fi

if [ "_$CALLXRL" == "_" ]
then
    if which call_xrl > /dev/null 2>&1
	then
	CALLXRL=call_xrl
    else
	CALLXRL=/usr/local/xorp/sbin/call_xrl
    fi
fi

XRLDIR=${XRLDIR:-${srcdir}/../xrl}

get_configured_interface_names()
{
    echo "get_configured_interface_names" $*
    $CALLXRL "finder://fea/ifmgr/0.1/get_configured_interface_names"
}

start_fea_transaction()
{
    if [ $# -eq 0 ] ; then
	tid=`$CALLXRL "finder://fea/ifmgr/0.1/start_transaction" | sed 's/.*=//'`
	err=$?
	echo $tid
	return $err
    fi

    cat >&2 <<EOF
usage: start_transaction 
       resulting transaction id is echoed on stdout on success
EOF
    return 255
}

commit_fea_transaction()
{
    echo "commit_transaction" $*
    if [ $# -eq 1 ] ; then
	$CALLXRL "finder://fea/ifmgr/0.1/commit_transaction?tid:u32=$1"
	return $?
    fi
    cat >&2 <<EOF
usage: commit_transaction <tid>
       where <tid> is the id of the transaction to be committed.
EOF
    return 255
}

abort_fea_transaction()
{
    echo "abort_transaction" $*
    if [ $# -eq 1 ] ; then
	$CALLXRL "finder://fea/ifmgr/0.1/abort_transaction?tid:u32=$1"
	return $?
    fi
    cat >&2 <<EOF
usage: abort_transaction <tid>
       where <tid> is the id of the transaction to be aborted.
EOF
    return 255
}

create_interface()
{
    echo "create_interface" $*
    $CALLXRL "finder://fea/ifmgr/0.1/create_interface?tid:u32=$1&ifname:txt=$2"
}

delete_interface()
{
    echo "delete_interface" $*
    $CALLXRL "finder://fea/ifmgr/0.1/delete_interface?tid:u32=$1&ifname:txt=$2"
}

enable_interface()
{
    echo "enable_interface" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_interface_enabled?tid:u32=$1&ifname:txt=$2&enabled:bool=true"
}

disable_interface()
{
    echo "disable_interface" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_interface_enabled?tid:u32=$1&ifname:txt=$2&enabled:bool=false"
}

configure_all_interfaces_from_system()
{
    echo "configure_all_interfaces_from_system" $*
    $CALLXRL "finder://fea/ifmgr/0.1/configure_all_interfaces_from_system?tid:u32=$1&enable:bool=$2"
}

configure_interface_from_system()
{
    echo "configure_interface_from_system" $*
    $CALLXRL "finder://fea/ifmgr/0.1/configure_interface_from_system?tid:u32=$1&ifname:txt=$2&enable:bool=$3"
}

set_mac()
{
    echo "set_mac" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_mac?tid:u32=$1&ifname:txt=$2&mac:mac=$3"
}

get_configured_mac()
{
    echo "get_configured_mac" $*
    $CALLXRL "finder://fea/ifmgr/0.1/get_configured_mac?ifname:txt=$1"
}

set_mtu()
{
    echo "set_mtu" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_mtu?tid:u32=$1&ifname:txt=$2&mtu:u32=$3"
}

get_configured_mtu()
{
    echo "get_configured_mtu" $*
    $CALLXRL "finder://fea/ifmgr/0.1/get_configured_mtu?ifname:txt=$1"
}

get_configured_vif_names()
{
    echo "get_configured_vif_names" $*
    $CALLXRL "finder://fea/ifmgr/0.1/get_configured_vif_names?ifname:txt=$1"
}

create_vif()
{
    echo "create_vif" $*
    $CALLXRL "finder://fea/ifmgr/0.1/create_vif?tid:u32=$1&ifname:txt=$2&vif:txt=$3"
}

delete_vif()
{
    echo "delete_vif" $*
    $CALLXRL "finder://fea/ifmgr/0.1/delete_vif?tid:u32=$1&ifname:txt=$2&vif:txt=$3"
}

enable_vif()
{
    echo "enable_vif" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_vif_enabled?tid:u32=$1&ifname:txt=$2&vif:txt=$3&enabled:bool=true"
}

disable_vif()
{
    echo "disable_vif" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_vif_enabled?tid:u32=$1&ifname:txt=$2&vif:txt=$3&enabled:bool=false"
}

get_configured_vif_addresses4()
{
    echo "get_configured_vif_addresses4" $*
    $CALLXRL "finder://fea/ifmgr/0.1/get_configured_vif_addresses4?ifname:txt=$1&vif:txt=$2"
}

create_address4()
{
    echo "create_address4" $*
    $CALLXRL "finder://fea/ifmgr/0.1/create_address4?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv4=$4"
}

delete_address4()
{
    echo "delete_address4" $*
    $CALLXRL "finder://fea/ifmgr/0.1/delete_address4?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv4=$4"
}

enable_address4()
{
    echo "enable_address4" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_address_enabled4?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv4=$4&enabled:bool=true"
}

disable_address4()
{
    echo "disable_address4" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_address_enabled4?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv4=$4&enabled:bool=false"
}

set_prefix4()
{
    echo "set_prefix4" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_prefix4?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv4=$4&prefix_len:u32=$5"
}

get_configured_prefix4()
{
    echo "get_configured_prefix4" $*
    $CALLXRL "finder://fea/ifmgr/0.1/get_configured_prefix4?ifname:txt=$1&vif:txt=$2&address:ipv4=$3"
}

set_broadcast4()
{
    echo "set_broadcast4" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_broadcast4?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv4=$4&broadcast:ipv4=$5"
}

get_configured_broadcast4()
{
    echo "get_configured_broadcast4" $*
    $CALLXRL "finder://fea/ifmgr/0.1/get_configured_broadcast4?ifname:txt=$1&vif:txt=$2&address:ipv4=$3"
}

get_configured_vif_addresses6()
{
    echo "get_configured_vif_addresses6" $*
    $CALLXRL "finder://fea/ifmgr/0.1/get_configured_vif_addresses6?ifname:txt=$1&vif:txt=$2"
}

create_address6()
{
    echo "create_address6" $*
    $CALLXRL "finder://fea/ifmgr/0.1/create_address6?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv6=$4"
}

delete_address6()
{
    echo "delete_address6" $*
    $CALLXRL "finder://fea/ifmgr/0.1/delete_address6?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv6=$4"
}

enable_address6()
{
    echo "enable_address6" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_address_enabled6?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv6=$4&enabled:bool=true"
}

disable_address6()
{
    echo "disable_address6" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_address_enabled6?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv6=$4&enabled:bool=false"
}

set_prefix6()
{
    echo "set_prefix6" $*
    $CALLXRL "finder://fea/ifmgr/0.1/set_prefix6?tid:u32=$1&ifname:txt=$2&vif:txt=$3&address:ipv6=$4&prefix_len:u32=$5"
}

get_configured_prefix6()
{
    echo "get_configured_prefix6" $*
    $CALLXRL "finder://fea/ifmgr/0.1/get_configured_prefix6?ifname:txt=$1&vif:txt=$2&address:ipv6=$3"
}

start_redist_transaction4()
{
    if [ $# -eq 0 ] ; then
	tid=`$CALLXRL "finder://fea/redist_transaction4/0.1/start_transaction" | sed 's/.*=//'`
	err=$?
	echo $tid
	return $err
    fi

    cat >&2 <<EOF
usage: start_redist_transaction4
       resulting transaction id is echoed on stdout on success
EOF
    return 255
}

start_redist_transaction6()
{
    if [ $# -eq 0 ] ; then
	tid=`$CALLXRL "finder://fea/redist_transaction6/0.1/start_transaction" | sed 's/.*=//'`
	err=$?
	echo $tid
	return $err
    fi

    cat >&2 <<EOF
usage: start_redist_transaction6
       resulting transaction id is echoed on stdout on success
EOF
    return 255
}

commit_redist_transaction4()
{
    echo "commit_redist_transaction4" $*
    if [ $# -eq 1 ] ; then
	$CALLXRL "finder://fea/redist_transaction4/0.1/commit_transaction?tid:u32=$1"
	return $?
    fi
    cat >&2 <<EOF
usage: commit_redist_transaction4 <tid>
       where <tid> is the id of the transaction to be committed.
EOF
    return 255
}

commit_redist_transaction6()
{
    echo "commit_redist_transaction6" $*
    if [ $# -eq 1 ] ; then
	$CALLXRL "finder://fea/redist_transaction6/0.1/commit_transaction?tid:u32=$1"
	return $?
    fi
    cat >&2 <<EOF
usage: commit_redist_transaction6 <tid>
       where <tid> is the id of the transaction to be committed.
EOF
    return 255
}

abort_redist_transaction4()
{
    echo "abort_redist_transaction4" $*
    if [ $# -eq 1 ] ; then
	$CALLXRL "finder://fea/redist_transaction4/0.1/abort_transaction?tid:u32=$1"
	return $?
    fi
    cat >&2 <<EOF
usage: abort_redist_transaction4 <tid>
       where <tid> is the id of the transaction to be aborted.
EOF
    return 255
}

abort_redist_transaction6()
{
    echo "abort_redist_transaction6" $*
    if [ $# -eq 1 ] ; then
	$CALLXRL "finder://fea/redist_transaction6/0.1/abort_transaction?tid:u32=$1"
	return $?
    fi
    cat >&2 <<EOF
usage: abort_redist_transaction6 <tid>
       where <tid> is the id of the transaction to be aborted.
EOF
    return 255
}

redist_transaction4_add_route()
{
    if [ $# -ne 8 ] ; then
	cat >&2 <<EOF
usage: redist_transaction4_add_route <tid> <dest net> <nexthop> <ifname> <vifname> <metric> <admin_distance> <cookie> <protocol_origin>
eg:    redist_transaction4_add_route 6987662 187.1.0.0/16 164.27.13.1 ed0 10 20 all BGP
EOF
	return 127
    fi

    $CALLXRL "finder://fea/redist_transaction4/0.1/add_route?tid:u32=$1&dst:ipv4net=$2&nexthop:ipv4=$3&ifname:txt=$4&vifname:txt=$5&metric:u32=$6&admin_distance:u32=$7&protocol_origin:txt=$8"
}

redist_transaction4_delete_route()
{
    if [ $# -ne 2 ] ; then
	cat >&2 <<EOF
usage: redist_transaction4_delete_route <tid> <dest net>
eg:    redist_transaction4_delete_route 276567373 187.1.0.0/16
EOF
	return 127
    fi

    $CALLXRL "finder://fea/redist_transaction4/0.1/delete_route?tid:u32=$1&network:ipv4net=$2"
}

lookup_route_by_dest4()
{
    echo -n "lookup_route_by_dest4" $* "-> " 
    $CALLXRL "finder://fea/fti/0.2/lookup_route_by_dest4?dst:ipv4=$1"
}

lookup_route_by_network4()
{
    echo -n "lookup_route_by_network4" $* "-> " 
    $CALLXRL "finder://fea/fti/0.2/lookup_route_by_network4?dst:ipv4net=$1"
}

have_ipv4()
{
    echo -n "have_ipv4" $* "-> "
    $CALLXRL "finder://fea/fti/0.2/have_ipv4"
}

have_ipv6()
{
    echo -n "have_ipv6" $* "-> "
    $CALLXRL "finder://fea/fti/0.2/have_ipv6"
}

get_unicast_forwarding_enabled4()
{
    echo -n "get_unicast_forwarding_enabled4" $* "-> "
    $CALLXRL "finder://fea/fti/0.2/get_unicast_forwarding_enabled4"
}

get_unicast_forwarding_enabled6()
{
    echo -n "get_unicast_forwarding_enabled6" $* "-> "
    $CALLXRL "finder://fea/fti/0.2/get_unicast_forwarding_enabled6"
}

set_unicast_forwarding_enabled4()
{
    echo "set_unicast_forwarding_enabled4" $*
    if [ $# -eq 1 ] ; then
	$CALLXRL "finder://fea/fti/0.2/set_unicast_forwarding_enabled4?enabled:bool=$1"
	return $?
    fi
    cat >&2 <<EOF
usage: set_unicast_fowarding_enabled4 <enabled>
       where <enabled> is set to true if we want to enable IPv4 unicast forwarding, otherwise is set to false.
EOF
    return 255
}

set_unicast_forwarding_enabled6()
{
    echo "set_unicast_forwarding_enabled6" $*
    if [ $# -eq 1 ] ; then
	$CALLXRL "finder://fea/fti/0.2/set_unicast_forwarding_enabled6?enabled:bool=$1"
	return $?
    fi
    cat >&2 <<EOF
usage: set_unicast_fowarding_enabled6 <enabled>
       where <enabled> is set to true if we want to enable IPv6 unicast forwarding, otherwise is set to false.
EOF
    return 255
}

shutdown()
{
    echo "shutdown" $*
    $CALLXRL "finder://fea/common/0.1/shutdown"
}

validate_xrls()
{
#
# Check that xrls in this script are valid.  Order of arguments is
# expected to match those in file containing Xrls: this is a laziness
# requirement and not an xrl requirement. A shell is almost certainly
# the wrong place for this.
#
# STOPLOOKING
#
    script_name="${srcdir}/fea_xrl_shell_funcs.sh"
    script_xrls=`cat ${script_name} | sed -n '1,/STOPLOOKING/p' | sed -n '/finder:\/\// p' | sed 's/[^"]*"\([^"]*\).*/\1/g' | sed 's/=[^-&]*//g' | sed 's/->.*//g'`
    source_xrl_files="${XRLDIR}/targets/*.xrls"

    match_count=0
    bad_count=0
    for i in ${script_xrls} ; do
	found="no"
	for file in ${source_xrl_files} ; do
	    source_xrls=`cat ${file} | grep '://' | sed 's/->.*//g'`
	    for j in ${source_xrls} ; do
		if [ ${i} = ${j} ] ; then
		    found="yes"
		    match_count=`expr ${match_count} + 1`
		    break
		fi
		stripped_i=`echo ${i} | sed 's/\?.*//'`
		stripped_j=`echo ${j} | sed 's/\?.*//'`
		if [ ${stripped_i} = ${stripped_j} ] ; then
		    found="yes"
		    echo "Warning mismatch in file ${file}:"
		    echo "	script has \"${i}\""
		    echo "	file   has \"${j}\""
		    bad_count=`expr ${bad_count} + 1`
		    break
		fi
	    done
	    if [ "${found}" = "yes" ] ; then
		break
	    fi
	done
	if [ "${found}" = "no" ] ; then
	    echo "No match for ${i} in ${source_xrl_files}"
	    bad_count=`expr ${bad_count} + 1`
	fi
    done
    status="Summary: ${match_count} xrls okay, ${bad_count} xrls bad."
    rule=`echo ${status} | sed 's/[A-z0-9,:. ]/-/g'`
    echo ${rule}
    echo ${status}
    echo ${rule}
    echo $*
    unset script_xrls
    unset source_xrls

    return ${bad_count}
}

# We have arguments.
if [ $# != 0 ]
then
    $*
fi

# Local Variables:
# mode: shell-script
# sh-indentation: 4
# End:
