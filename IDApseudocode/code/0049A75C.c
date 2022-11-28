void __fastcall format_pppoe_br_more_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 3 )
    snprintf(a3, a4, "{\"wan_name\":\"%s\",\"wan_iface\":%s,\"wan_num\":%s},", *a1, a1[1], a1[2]);
}

