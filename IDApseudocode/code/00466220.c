void __fastcall format_time_group_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 3 )
    snprintf(a3, a4, "{\"n\":\"%s\",\"t\":\"%s\",\"id\":\"%s\"},", a1[2], a1[1], *a1);
}

