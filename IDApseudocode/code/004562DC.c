void __fastcall format_spqos_data(const char **a1, int a2, char *a3, int a4)
{
  const char *v4; // $s3

  if ( a2 >= 17 )
  {
    v4 = *a1;
    if ( strcmp(*a1, "aaabbbzzzf") )
      snprintf(
        a3,
        a4,
        "{\"name\":\"%s\",\"en\":%s,\"rpri\":%s,\"dev_prio\":%s,\"hi_prio\":%s,\"bh\":%s,\"type\":%s,\"thd_type\":%s,\"sx"
        "\":%s,\"xx\":%s,\"ips\":\"%s\",\"wans\":\"%s\",\"thd\":\"%s\",\"shibie_id\":\"%s\",\"ipport\":\"%s\",\"time\":\""
        "%s\",\"flowed_val\":%s},",
        v4,
        a1[1],
        a1[2],
        a1[3],
        a1[4],
        a1[5],
        a1[6],
        a1[7],
        a1[8],
        a1[9],
        a1[10],
        a1[11],
        a1[12],
        a1[13],
        a1[14],
        a1[15],
        a1[16]);
  }
}

