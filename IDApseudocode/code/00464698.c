int __fastcall time_group_modify(int a1, int a2)
{
  FILE *v3; // $v0
  FILE *v4; // $s1
  int v5; // $s6
  void *v6; // $v0
  void *v7; // $s7
  int v8; // $s4
  int v9; // $v0
  int v10; // $s4
  int v11; // $v0
  int v12; // $s4
  int v13; // $v0
  int v14; // $s4
  int v15; // $v0
  int v16; // $s4
  int v17; // $v0
  int v18; // $s4
  int v19; // $v0
  int v20; // $s4
  int v21; // $v0
  int v22; // $s4
  int v23; // $v0
  int v24; // $s4
  int v25; // $v0
  int v26; // $s4
  int v27; // $v0
  int v28; // $v0
  _DWORD *v29; // $s5
  int v30; // $s6
  int v31; // $fp
  int v32; // $v0
  int v33; // $s4
  _BYTE *v34; // $v0
  int v35; // $v0
  int **v36; // $s0
  int *v37; // $s7
  int *v38; // $s2
  int v39; // $a3
  int v42[4]; // [sp+20h] [-28h] BYREF
  void **v43; // [sp+30h] [-18h]
  int v44; // [sp+34h] [-14h]
  char *v45; // [sp+38h] [-10h]
  void *v46; // [sp+3Ch] [-Ch]
  char *v47; // [sp+40h] [-8h]
  const char *v48; // [sp+44h] [-4h]

  v45 = "a";
  v3 = fopen("/root/time_group/time_vue.cfg", "w");
  if ( v3 && (v4 = v3, v5 = cJSON_CreateArray(), (v44 = v5) != 0) )
  {
    v47 = "a";
    _mem_malloc(0x200000, "time_group_modify", 611);
    v7 = v6;
    v46 = v6;
    if ( v6 )
    {
      v8 = cJSON_CreateObject();
      cJSON_AddStringToObject(v8, &off_646D58, &unk_646D7C);
      v9 = cJSON_AddArrayToObject(v8, "list");
      mrprot_rule_check_used_group(a1, 1, v7, 0x200000u, v9);
      cJSON_AddItemToArray(v5, v8);
      v10 = cJSON_CreateObject();
      cJSON_AddStringToObject(v10, &off_646D58, "wys macfilter add");
      v11 = cJSON_AddArrayToObject(v10, "list");
      macfilter_rule_check_used_group((const char *)a1, v7, 0x200000u, v11);
      cJSON_AddItemToArray(v5, v10);
      v12 = cJSON_CreateObject();
      cJSON_AddStringToObject(v12, &off_646D58, "wys ctrule add ddos");
      v13 = cJSON_AddArrayToObject(v12, "list");
      ddos_rule_check_used_group(a1, 1, v7, 0x200000u, v13);
      cJSON_AddItemToArray(v5, v12);
      v14 = cJSON_CreateObject();
      cJSON_AddStringToObject(v14, &off_646D58, "wys lvrule add");
      v15 = cJSON_AddArrayToObject(v14, "list");
      xwgl_rule_check_used_group(a1, 1, v7, 0x200000u, v15);
      cJSON_AddItemToArray(v5, v14);
      v16 = cJSON_CreateObject();
      cJSON_AddStringToObject(v16, &off_646D58, "wys url add");
      v17 = cJSON_AddArrayToObject(v16, "list");
      url_rule_check_used_group(a1, 1, v7, 0x200000u, v17);
      cJSON_AddItemToArray(v5, v16);
      v18 = cJSON_CreateObject();
      cJSON_AddStringToObject(v18, &off_646D58, "wys lvrule hbmd");
      v19 = cJSON_AddArrayToObject(v18, "list");
      qq_rule_check_used_group((const char *)a1, v7, 0x200000u, v19);
      cJSON_AddItemToArray(v5, v18);
      v20 = cJSON_CreateObject();
      cJSON_AddStringToObject(v20, &off_646D58, "wys qos sprule add \"pri\"");
      v21 = cJSON_AddArrayToObject(v20, "list");
      qos_rule_check_used_group((int)&off_645B94, a1, 1, (int)v7, 0x200000u, v21);
      cJSON_AddItemToArray(v5, v20);
      v22 = cJSON_CreateObject();
      cJSON_AddStringToObject(v22, &off_646D58, "wys qos sprule add \"xz\"");
      v23 = cJSON_AddArrayToObject(v22, "list");
      qos_rule_check_used_group((int)"xz", a1, 1, (int)v7, 0x200000u, v23);
      cJSON_AddItemToArray(v5, v22);
      v24 = cJSON_CreateObject();
      cJSON_AddStringToObject(v24, &off_646D58, "wys qos sprule add \"bz\"");
      v25 = cJSON_AddArrayToObject(v24, "list");
      qos_rule_check_used_group((int)"bz", a1, 1, (int)v7, 0x200000u, v25);
      cJSON_AddItemToArray(v5, v24);
      v26 = cJSON_CreateObject();
      cJSON_AddStringToObject(v26, &off_646D58, "wys ctrule add ct");
      v27 = cJSON_AddArrayToObject(v26, "list");
      ctxz_rule_check_used_group(a1, 1, v7, 0x200000u, v27);
      cJSON_AddItemToArray(v5, v26);
      v28 = _get_timer_man_list();
      v29 = *(_DWORD **)(v5 + 8);
      v30 = v28;
      if ( v29 )
      {
        v43 = &off_646D58;
        v31 = 0;
        v48 = "list";
        do
        {
          while ( 1 )
          {
            v32 = cJSON_GetObjectItem(v29, v43);
            v33 = v32;
            if ( v32 )
            {
              v34 = *(_BYTE **)(v32 + 16);
              if ( v34 )
              {
                if ( *v34 )
                {
                  v35 = cJSON_GetObjectItem(v29, v48);
                  if ( v35 )
                  {
                    v36 = *(int ***)(v35 + 8);
                    if ( v36 )
                      break;
                  }
                }
              }
            }
            v29 = (_DWORD *)*v29;
            if ( !v29 )
              goto LABEL_17;
          }
          do
          {
            v37 = _get_timer_man_tid(v30, *(const char **)(v33 + 16), (const char *)v36[4]);
            v38 = v37 + 4096;
            do
            {
              v39 = *v37;
              if ( *v37++ == 0 )
                break;
              v31 = 1;
              fprintf(v4, "mr_%s=%d\n", (const char *)v36[4], v39);
            }
            while ( v38 != v37 );
            v36 = (int **)*v36;
          }
          while ( v36 );
          v29 = (_DWORD *)*v29;
        }
        while ( v29 );
LABEL_17:
        fclose(v4);
        if ( v31 )
        {
          v42[0] = (int)"timer_mod.sh";
          v42[1] = (int)"vue";
          v42[2] = a2;
          v42[3] = 0;
          eval(v42, 0, 0, 0);
        }
      }
      else
      {
        fclose(v4);
      }
    }
    else
    {
      v30 = 0;
    }
  }
  else
  {
    v30 = 0;
    v44 = 0;
    v46 = 0;
    v47 = "a";
  }
  unlink(v45 + 27996);
  cJSON_Delete(v44);
  cJSON_Delete(v30);
  _mem_free(v46);
  return 0;
}
// 464740: variable 'v6' is possibly undefined
// 645B94: using guessed type void *off_645B94;
// 646D58: using guessed type void *off_646D58;
// 6A8258: using guessed type int cJSON_CreateObject(void);
// 6A83A8: using guessed type int __fastcall cJSON_AddStringToObject(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8490: using guessed type int cJSON_CreateArray(void);
// 6A86D4: using guessed type int __fastcall cJSON_AddArrayToObject(_DWORD, _DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A8858: using guessed type int __fastcall cJSON_AddItemToArray(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);

