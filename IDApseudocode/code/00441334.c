void __fastcall format_wanll_history_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 2 )
    snprintf(a3, a4, "{\"u\":\"%s\",\"d\":\"%s\"},", *a1, a1[1]);
}

