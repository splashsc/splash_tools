char *__fastcall sub_424324(char *a1, const time_t *a2)
{
  struct tm *v3; // $v0
  time_t v5; // [sp+28h] [-Ch] BYREF

  if ( a2 )
  {
    v3 = gmtime(a2);
  }
  else
  {
    time(&v5);
    v3 = gmtime(&v5);
  }
  sprintf(a1, aD_0, v3->tm_year + 1900, v3->tm_mon + 1, v3->tm_mday, v3->tm_hour, v3->tm_min, v3->tm_sec);
  return a1;
}

