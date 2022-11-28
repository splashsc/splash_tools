void __fastcall format_url_member_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 3 )
    snprintf(a3, a4, "{\"n\":\"%s\",\"u\":\"%s\",\"g\":%s},", *a1, a1[1], a1[2]);
}

