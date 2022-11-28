int _get_timer_man_list()
{
  int v0; // $s3
  FILE *v1; // $v0
  FILE *v2; // $s1
  int v3; // $v0
  int v4; // $s6
  int v5; // $v1
  char v7[1024]; // [sp+18h] [-420h] BYREF
  char v8[8]; // [sp+418h] [-20h] BYREF
  const void *v9; // [sp+420h] [-18h]

  memset(v7, 0, sizeof(v7));
  v0 = cJSON_CreateArray();
  v1 = fopen("/root/timer_man.cfg", "r");
  if ( v1 )
  {
    v2 = v1;
    if ( v0 )
    {
      while ( fgets(v7, 1024, v2) )
      {
        if ( v7[0] == 100 )
        {
          split_string(v7, 59, v8, 8);
          if ( v9 )
          {
            if ( !memcmp(v9, "wys", 3u) )
            {
              v4 = cJSON_CreateObject();
              v3 = atoi(&v7[1]);
              cJSON_AddNumberToObject(v4, &off_646D54, v3, v5);
              cJSON_AddStringToObject(v4, &off_646D58, v9);
              cJSON_AddItemToArray(v0, v4);
            }
          }
        }
        memset(v7, 0, sizeof(v7));
      }
    }
    fclose(v2);
  }
  return v0;
}
// 46447C: variable 'v5' is possibly undefined
// 646D54: using guessed type void *off_646D54;
// 646D58: using guessed type void *off_646D58;
// 6A8258: using guessed type int cJSON_CreateObject(void);
// 6A83A8: using guessed type int __fastcall cJSON_AddStringToObject(_DWORD, _DWORD, _DWORD);
// 6A8490: using guessed type int cJSON_CreateArray(void);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A87C8: using guessed type int __fastcall cJSON_AddNumberToObject(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8858: using guessed type int __fastcall cJSON_AddItemToArray(_DWORD, _DWORD);

