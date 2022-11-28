void __fastcall format_acc_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 11 )
    snprintf(
      a3,
      a4,
      "{\"name\":\"%s\",\"en\":%s,\"ips\":\"%s\",\"time\":\"%s\",\"log\":\"%s\",\"rpri\":\"%s\",\"act\":\"%s\",\"thd_type"
      "\":\"%s\",\"thd\":\"%s\",\"ipport\":\"%s\",\"ruleips\":\"%s\"},",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5],
      a1[6],
      a1[7],
      a1[8],
      a1[9],
      a1[10]);
}

