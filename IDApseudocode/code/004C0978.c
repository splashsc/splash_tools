int __fastcall sub_4C0978(int a1)
{
  char *v1; // $v0
  const char *v3; // $a1
  const char *v4; // $s2
  char **v5; // $s0
  int v6; // $s1
  int v7; // $a0
  char **v8; // $v1
  const char *v9; // $v0
  char *v10; // $t0
  char *v11; // $a3
  char *v12; // $a2
  char *v13; // $a1
  char *v15; // $v1
  char *v16; // [sp+18h] [-704h] BYREF
  const char *v17; // [sp+1Ch] [-700h]
  char *v18; // [sp+20h] [-6FCh]
  char *v19; // [sp+24h] [-6F8h]
  char *v20; // [sp+28h] [-6F4h]
  int v21; // [sp+2Ch] [-6F0h]
  char v22[256]; // [sp+418h] [-304h] BYREF
  char v23[256]; // [sp+518h] [-204h] BYREF
  char v24[260]; // [sp+618h] [-104h] BYREF

  v1 = httpd_get_parm(a1, "n");
  if ( v1 )
  {
    v3 = ll_ssstt;
    if ( ll_ssstt )
    {
      v4 = v1;
      v5 = &off_679810;
      v6 = 0;
      while ( 1 )
      {
        v5 += 2;
        if ( !strcmp(v4, v3) )
          break;
        v3 = *(v5 - 2);
        ++v6;
        if ( !v3 )
          goto LABEL_9;
      }
      sprintf(v23, "/etc/def_mrcl/%s.txt", v4);
      sprintf(v24, "/etc/mrcl/%s.txt", v4);
      sprintf(v22, "mrcl_%s", v4);
      if ( f_exists(v23) )
      {
        v16 = "cp";
        v17 = "-f";
        v18 = v23;
        v19 = v24;
        v20 = 0;
        eval(&v16, 0, 0, 0);
        v16 = "wys";
        v15 = (&ll_ssstt)[2 * v6 + 1];
        v17 = "mrcl_ips";
        v18 = v15;
        v19 = (char *)v4;
        v20 = v24;
        v21 = 0;
        eval(&v16, 0, 0, 0);
      }
      nvram_unset(v22);
      jhl_parm_commit(v7);
    }
  }
LABEL_9:
  v8 = &v16;
  v9 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v10 = *(char **)v9;
    v11 = (char *)*((_DWORD *)v9 + 1);
    v12 = (char *)*((_DWORD *)v9 + 2);
    v13 = (char *)*((_DWORD *)v9 + 3);
    v9 += 16;
    *v8 = v10;
    v8[1] = v11;
    v8[2] = v12;
    v8[3] = v13;
    v8 += 4;
  }
  while ( v9 != "}" );
  *(_WORD *)v8 = *(_WORD *)v9;
  return httpd_cgi_ret(a1, (char *)&v16, 33, 4);
}
// 4C0AC4: variable 'v7' is possibly undefined
// 679808: using guessed type char *ll_ssstt;
// 679810: using guessed type char *off_679810;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A846C: using guessed type int __fastcall f_exists(_DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);

