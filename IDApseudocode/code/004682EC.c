void __fastcall format_xwgl_ref_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 10 )
    snprintf(
      a3,
      a4,
      "{\"name\":\"%s\",\"en\":%s,\"user_id\":\"%s\",\"shibie_name\":\"%s\",\"time\":\"%s\",\"act\":%s,\"log\":%s,\"rpri\""
      ":%s,\"ipport\":\"%s\",\"ruleips\":\"%s\"},",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5],
      a1[6],
      a1[7],
      a1[8],
      a1[9]);
}

