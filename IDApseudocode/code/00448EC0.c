void __fastcall format_wan_extend_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 4 )
    snprintf(a3, a4, "{\"wan_name\":\"%s\",\"wan_iface\":%s,\"wan_num\":%s,\"wan_vlan\":%s},", *a1, a1[1], a1[2], a1[3]);
}

