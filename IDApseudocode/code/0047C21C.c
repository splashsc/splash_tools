time_t __fastcall timeconvert(char *a1, struct tm *a2)
{
  int v4; // $v0
  int v6; // $v0
  bool v7; // dc
  int v8; // $v0
  int v9; // $v1

  memset(a2, 0, sizeof(struct tm));
  if ( strchr(a1, 45) )
    v4 = sscanf(a1, "%d-%d-%d %d:%d", &a2->tm_year, &a2->tm_mon, &a2->tm_mday, &a2->tm_hour, &a2->tm_min);
  else
    v4 = sscanf(a1, "%d/%d/%d %d:%d", &a2->tm_year, &a2->tm_mon, &a2->tm_mday, &a2->tm_hour, &a2->tm_min);
  if ( v4 != 5 )
    return 0;
  v6 = a2->tm_year;
  v7 = v6 < 1900;
  v8 = v6 - 1900;
  if ( v7 )
    return 0;
  v9 = a2->tm_mon - 1;
  a2->tm_year = v8;
  a2->tm_mon = v9;
  return mktime(a2);
}

