void __fastcall format_url_rule_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 9 )
    snprintf(
      a3,
      a4,
      "{\"n\":\"%s\",\"en\":%s,\"ips\":\"%s\",\"u\":\"%s\",\"time\":\"%s\",\"log\":%s,\"rpri\":%s,\"act\":%s,\"flag\":%s},",
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

