void __fastcall format_dns_more_dnswan_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 4 )
    snprintf(a3, a4, "{\"n\":\"%s\",\"id\":\"%s\",\"dns\":\"%s\",\"wans\":\"%s\"},", *a1, a1[1], a1[2], a1[3]);
}

