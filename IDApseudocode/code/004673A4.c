void __fastcall format_hbmd_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 3 )
    snprintf(a3, a4, "{\"n\":\"%s\",\"qq\":\"%s\",\"t\":\"%s\"},", *a1, a1[1], a1[2]);
}

