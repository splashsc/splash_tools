int __fastcall sub_4AF8F4(int a1)
{
  char *v1; // $v0
  FILE *v2; // $v0
  FILE *v3; // $s2
  int v4; // $s1
  const char **v5; // $v1
  const char *v6; // $v0
  const char *v7; // $t0
  const char *v8; // $a3
  const char *v9; // $a2
  const char *v10; // $a1
  const char *v12; // $t0
  const char *v13; // $a3
  const char *v14; // $a2
  const char *v15; // $a1
  const char *v16; // [sp+18h] [-520h] BYREF
  int *v17; // [sp+1Ch] [-51Ch]
  int v18; // [sp+20h] [-518h]
  char v19[256]; // [sp+418h] [-120h] BYREF
  int v20; // [sp+518h] [-20h] BYREF
  int v21; // [sp+51Ch] [-1Ch]
  int v22; // [sp+520h] [-18h]
  int v23; // [sp+524h] [-14h]
  int v24; // [sp+528h] [-10h]
  int v25; // [sp+52Ch] [-Ch]
  const char *v26; // [sp+530h] [-8h]

  memset(v19, 0, sizeof(v19));
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v1 = httpd_get_parm(a1, "disk_name");
  if ( v1 && *v1 )
  {
    v16 = "umount";
    v17 = (int *)v1;
    v18 = 0;
    eval(&v16, 0, 0, 0);
    v5 = &v16;
    v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v12 = *(const char **)v6;
      v13 = (const char *)*((_DWORD *)v6 + 1);
      v14 = (const char *)*((_DWORD *)v6 + 2);
      v15 = (const char *)*((_DWORD *)v6 + 3);
      v6 += 16;
      *v5 = v12;
      v5[1] = v13;
      v5[2] = v14;
      v5[3] = v15;
      v5 += 4;
    }
    while ( v6 != "}" );
  }
  else
  {
    jhl_system("df > /tmp/df_file");
    v2 = fopen("/tmp/df_file", "r");
    v3 = v2;
    if ( v2 )
    {
      fgets(v19, 256, v2);
      memset(v19, 0, sizeof(v19));
      v4 = 0;
      v26 = "smbd";
      while ( fgets(v19, 256, v3) )
      {
        if ( strstr(v19, "/dev/") )
        {
          if ( ++v4 == 1 )
          {
            killall_tk(v26);
            sleep(1u);
          }
          sscanf(v19, "%s", &v20);
          v16 = "umount";
          v17 = &v20;
          v18 = 0;
          eval(&v16, 0, 0, 0);
        }
        v20 = 0;
        v21 = 0;
        v22 = 0;
        v23 = 0;
        v24 = 0;
        v25 = 0;
        memset(v19, 0, sizeof(v19));
      }
      fclose(v3);
    }
    remove("/tmp/df_file");
    v5 = &v16;
    v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v7 = *(const char **)v6;
      v8 = (const char *)*((_DWORD *)v6 + 1);
      v9 = (const char *)*((_DWORD *)v6 + 2);
      v10 = (const char *)*((_DWORD *)v6 + 3);
      v6 += 16;
      *v5 = v7;
      v5[1] = v8;
      v5[2] = v9;
      v5[3] = v10;
      v5 += 4;
    }
    while ( v6 != "}" );
  }
  *(_WORD *)v5 = *(_WORD *)v6;
  return httpd_cgi_ret(a1, (char *)&v16, 33, 4);
}
// 6A82E4: using guessed type int __fastcall killall_tk(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8594: using guessed type int __fastcall jhl_system(_DWORD);

