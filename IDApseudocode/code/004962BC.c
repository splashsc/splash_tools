void __fastcall format_routers_static(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 6 )
    snprintf(
      a3,
      a4,
      "{\"dest\":\"%s\",\"gateway\":\"%s\",\"mask\":\"%s\",\"metric\":%s,\"ifname\":\"%s\",\"name\":\"%s\"},",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5]);
}

