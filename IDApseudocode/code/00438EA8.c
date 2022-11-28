int __fastcall sub_438EA8(int a1)
{
  char *v1; // $v0
  char *v2; // $s1
  char *v3; // $v0
  char *v4; // $s4
  char *v5; // $v0
  char *v6; // $s2
  char *v7; // $v0
  int *v8; // $v0
  int v9; // $a2
  int *v10; // $s3
  const char *v11; // $v0
  char *v12; // $v1
  int v13; // $t1
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  char *v18; // $s5
  _BOOL4 v19; // $v0
  char *v20; // $fp
  int v21; // $v0
  int v22; // $v0
  char *v23; // $a1
  int v24; // $fp
  size_t v25; // $v0
  int v26; // $t3
  int v27; // $fp
  int v28; // $v0
  int v29; // $a0
  char v30[64]; // [sp+28h] [-88h] BYREF
  char v31[32]; // [sp+68h] [-48h] BYREF
  int v32; // [sp+88h] [-28h] BYREF
  __int16 v33; // [sp+8Ch] [-24h]
  int v34; // [sp+90h] [-20h]
  char *v35; // [sp+94h] [-1Ch]
  int v36; // [sp+98h] [-18h]
  int v37; // [sp+9Ch] [-14h]
  char *format; // [sp+A0h] [-10h]
  char *v39; // [sp+A4h] [-Ch]
  char *v40; // [sp+A8h] [-8h]

  v32 = 0;
  v33 = 0;
  _mem_malloc(0x80000, "sdwan_hi_auto_asp", 1192);
  if ( v1 )
  {
    v2 = v1;
    _mem_malloc(0x80000, "sdwan_hi_auto_asp", 1198);
    v4 = v3;
    if ( v3 )
    {
      _mem_malloc(0x80000, "sdwan_hi_auto_asp", 1204);
      v6 = v5;
      if ( v5 )
      {
        _mem_malloc(0x80000, "sdwan_hi_auto_asp", 1210);
        v35 = v7;
        if ( v7 )
        {
          v8 = (int *)sdwan_get_ac_dev_list();
          *(_DWORD *)v2 = 13;
          *((_DWORD *)v2 + 3) = 1;
          *((_DWORD *)v2 + 1) = 0x80000;
          v10 = v8;
          if ( !jianhl_order_opt_fun(v2, 0x80000, v9) )
          {
            v40 = "a";
            jhl_parm_get("wysz_wan_out_rule", v6, 0x80000);
            sdwan_id_init_get(1);
            v18 = v2 + 102;
            if ( *((int *)v2 + 5) > 0 )
            {
              format = "%s";
              v36 = 0;
              v34 = 0;
              v39 = "%s|%d;";
              do
              {
                v20 = v18;
                if ( !memcmp(v18, &v32, 6u) )
                  v20 = v18 - 6;
                sdwan_check_in_ac(v10, (unsigned __int8 *)v18 - 50);
                if ( !v21 )
                {
                  v22 = sdwan_id_init_get(0);
                  v23 = v20;
                  v24 = v22;
                  MacToStr(v31, v23);
                  snprintf(v4, 0x80000, format, v6);
                  nvparm_del_str_too_too_long(v4, 59, 0, v31, 124, 0, v6);
                  v25 = strlen(v6);
                  if ( v24 == 0xFFFF )
                  {
                    v26 = 0xFFFF;
                  }
                  else
                  {
                    v37 = v24;
                    snprintf(&v6[v25], 0x80000 - v25, v39, v31, v24);
                    v26 = v37;
                  }
                  v27 = 0x80000 - v36;
                  v37 = 0x80000;
                  v28 = snprintf(&v35[v36], 0x80000 - v36, "%s|%d;", v31, v26);
                  if ( v28 >= v27 )
                    v28 = v37 - 1 - v36;
                  v36 += v28;
                }
                v19 = ++v34 < *((_DWORD *)v2 + 5);
                v18 += 976;
              }
              while ( v19 );
            }
            sdwan_id_init_get(2);
            wyaos_z_wan_out_set_macs(v35);
            nvram_set(v40 + 10056, v6);
            jhl_parm_commit(v29);
          }
        }
        else
        {
          v10 = 0;
        }
      }
      else
      {
        v35 = 0;
        v10 = 0;
      }
      _mem_free(v2);
      _mem_free(v4);
      if ( v6 )
        _mem_free(v6);
      if ( v35 )
        _mem_free(v35);
      if ( v10 )
        _mem_free(v10);
    }
    else
    {
      _mem_free(v2);
    }
  }
  v11 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v12 = v30;
  do
  {
    v13 = *(_DWORD *)v11;
    v14 = *((_DWORD *)v11 + 1);
    v15 = *((_DWORD *)v11 + 2);
    v16 = *((_DWORD *)v11 + 3);
    v11 += 16;
    *(_DWORD *)v12 = v13;
    *((_DWORD *)v12 + 1) = v14;
    *((_DWORD *)v12 + 2) = v15;
    *((_DWORD *)v12 + 3) = v16;
    v12 += 16;
  }
  while ( v11 != "}" );
  *(_WORD *)v12 = *(_WORD *)v11;
  return httpd_cgi_ret(a1, v30, 33, 4);
}
// 438F0C: variable 'v1' is possibly undefined
// 438F30: variable 'v3' is possibly undefined
// 438F50: variable 'v5' is possibly undefined
// 438F68: variable 'v7' is possibly undefined
// 438FB0: variable 'v9' is possibly undefined
// 4391C8: variable 'v21' is possibly undefined
// 439368: variable 'v29' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8500: using guessed type int __fastcall wyaos_z_wan_out_set_macs(_DWORD);
// 6A8560: using guessed type int __fastcall nvparm_del_str_too_too_long(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

