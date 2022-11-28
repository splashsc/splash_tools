int __fastcall sub_47DB24(int a1)
{
  char *v2; // $s2
  char *v3; // $s4
  char *v4; // $s3
  int v5; // $s3
  int v6; // $a2
  char v8[512]; // [sp+18h] [-318h] BYREF
  char v9[256]; // [sp+218h] [-118h] BYREF
  int v10; // [sp+318h] [-18h] BYREF
  int v11; // [sp+31Ch] [-14h]
  int v12; // [sp+320h] [-10h]
  int v13; // [sp+324h] [-Ch]
  int v14; // [sp+328h] [-8h]

  v2 = httpd_get_parm(a1, "t");
  v3 = httpd_get_parm(a1, "i");
  v4 = httpd_get_parm(a1, (char *)&off_649214);
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  if ( v3 )
    v11 = J_atoi(v3);
  if ( v4 )
    v5 = J_atoi(v4);
  else
    v5 = 0;
  strcpy(v8, "{}");
  if ( (!strcmp(v2, "tg") || !strcmp(v2, (const char *)&off_64D744)) && tg_url_get(v9, 256, &v10, v5) )
    v6 = sprintf(v8, "{\"u\":\"%s\"}", v9);
  else
    v6 = 2;
  return httpd_cgi_ret(a1, v8, v6, 4);
}
// 649214: using guessed type void *off_649214;
// 64D744: using guessed type void *off_64D744;
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

