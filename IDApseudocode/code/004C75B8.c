void __fastcall format_ipv6_router_static_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 4 )
    snprintf(a3, a4, "{\"dst\":\"%s\",\"gw\":\"%s\",\"dev\":\"%s\",\"name\":\"%s\"},", *a1, a1[1], a1[2], a1[3]);
}

