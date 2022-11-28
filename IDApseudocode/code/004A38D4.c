void __fastcall format_nat_base_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 8 )
    snprintf(
      a3,
      a4,
      "{\"en\":%s,\"prot\":\"%s\",\"src\":\"%s\",\"fport\":\"%s\",\"inport\":\"%s\",\"inip\":\"%s\",\"name\":\"%s\",\"wans\":\"%s\"},",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5],
      a1[6],
      a1[7]);
}

