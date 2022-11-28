void __fastcall format_dns_url_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 2 )
    snprintf(a3, a4, "{\"src\":\"%s\",\"dst\":\"%s\"},", *a1, a1[1]);
}

