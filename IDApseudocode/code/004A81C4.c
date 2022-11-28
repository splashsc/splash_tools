void __fastcall format_portward_nat_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 9 )
    snprintf(
      a3,
      a4,
      "{\"en\":%s,\"proto\":\"%s\",\"src\":\"%s\",\"out_port\":\"%s\",\"in_port\":\"%s\",\"in_addr\":\"%s\",\"name\":\"%s"
      "\",\"interface\":\"%s\",\"convert_addr\":\"%s\"}",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5],
      a1[6],
      a1[7],
      a1[8]);
}

