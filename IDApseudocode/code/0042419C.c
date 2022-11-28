char *__fastcall GetDateString(char *a1, const time_t *a2)
{
  int *v2; // $v0
  int *v4; // $v1
  int v5; // $t1
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  struct tm *v9; // $v0
  _DWORD v11[19]; // [sp+30h] [-50h] BYREF
  time_t v12; // [sp+7Ch] [-4h] BYREF

  v11[12] = "Sun";
  v11[13] = "Mon";
  v11[14] = "Tue";
  v2 = (int *)fdata;
  v11[15] = &off_4CF0FC;
  v11[16] = &unk_4CF100;
  v11[17] = &off_4CF104;
  v11[18] = &unk_4CF108;
  v4 = v11;
  do
  {
    v5 = *v2;
    v6 = v2[1];
    v7 = v2[2];
    v8 = v2[3];
    v2 += 4;
    *v4 = v5;
    v4[1] = v6;
    v4[2] = v7;
    v4[3] = v8;
    v4 += 4;
  }
  while ( v2 != &gl_httpd_admin_en );
  if ( a2 )
  {
    v9 = gmtime(a2);
  }
  else
  {
    time(&v12);
    v9 = gmtime(&v12);
  }
  sprintf(
    a1,
    "%s, %02d %s %d %02d:%02d:%02d GMT",
    (const char *)v11[v9->tm_wday + 12],
    v9->tm_mday,
    (const char *)v11[v9->tm_mon],
    v9->tm_year + 1900,
    v9->tm_hour,
    v9->tm_min,
    v9->tm_sec);
  return a1;
}
// 4CF0FC: using guessed type void *off_4CF0FC;
// 4CF104: using guessed type void *off_4CF104;
// 666140: using guessed type char *fdata[2];
// 666170: using guessed type int gl_httpd_admin_en;

