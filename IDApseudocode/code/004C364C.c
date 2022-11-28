void __fastcall format_mrprot_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 12 )
    snprintf(
      a3,
      a4,
      "{\"name\":\"%s\",\"en\":%s,\"ips\":\"%s\",\"thd\":\"%s\",\"thd_type\":\"%s\",\"time\":\"%s\",\"rpri\":%s,\"log\":%"
      "s,\"wans\":\"%s\",\"no_change\":\"%s\",\"shibie\":\"%s\",\"ipport\":\"%s\"},",
      *a1,
      a1[1],
      a1[2],
      a1[8],
      a1[7],
      a1[3],
      a1[5],
      a1[4],
      a1[6],
      a1[11],
      a1[9],
      a1[10]);
}

