void __fastcall format_dns_more_dnswan_rule_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 6 )
    snprintf(
      a3,
      a4,
      "{\"n\":\"%s\",\"en\":%s,\"hi\":%s,\"dns\":%s,\"wan\":%s,\"pri\":%s},",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5]);
}

