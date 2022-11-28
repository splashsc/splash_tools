void __fastcall format_wys_bonding_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 6 )
    snprintf(
      a3,
      a4,
      "{\"name\":\"%s\",\"port\":\"%s\",\"mode\":\"%s\",\"policy\":\"%s\",\"lw\":\"%s\",\"ifname\":\"%s\"},",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5]);
}

