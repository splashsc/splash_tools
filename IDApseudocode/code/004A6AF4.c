void __fastcall format_menu_nat_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 7 )
    snprintf(
      a3,
      a4,
      "{\"en\":%s,\"in_addr\":\"%s\",\"out_addr\":\"%s\",\"interface_id\":\"%s\",\"src\":\"%s\",\"out_port\":\"%s\",\"proto\":\"%s\"},",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5],
      a1[6]);
}

