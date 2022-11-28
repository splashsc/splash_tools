void __fastcall format_menu_nat_more_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 10 )
    snprintf(
      a3,
      a4,
      "{\"en\":%s,\"nat_inter_en\":\"%s\",\"src_addr\":\"%s\",\"src_netmask\":\"%s\",\"target_addr_type\":\"%s\",\"target"
      "_addr\":\"%s\",\"target_netmask\":\"%s\",\"interface\":\"%s\",\"to_address\":\"%s\",\"src\":\"%s\"},",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5],
      a1[6],
      a1[7],
      a1[8],
      a1[9]);
}

