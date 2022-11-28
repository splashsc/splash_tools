int __fastcall sub_45217C(int a1)
{
  int v2; // $v0
  __pid_t v3; // $s7
  const char *v4; // $s5
  char *v5; // $v0
  char *v6; // $s4
  unsigned int v7; // $s2
  unsigned int v8; // $s0
  __pid_t v9; // $a2
  char *v10; // $s7
  const char *v11; // $s5
  int v12; // $v0
  unsigned int v13; // $v0
  int v14; // $s2
  unsigned int v15; // $v0
  char v17[4100]; // [sp+18h] [-14A8h] BYREF
  char v18[1024]; // [sp+101Ch] [-4A4h] BYREF
  char v19[128]; // [sp+141Ch] [-A4h] BYREF
  int v20; // [sp+149Ch] [-24h] BYREF
  int v21; // [sp+14A0h] [-20h] BYREF
  char *s; // [sp+14A8h] [-18h]
  char *v23; // [sp+14ACh] [-14h]
  char *v24; // [sp+14B0h] [-10h]
  char *v25; // [sp+14B4h] [-Ch]
  char *v26; // [sp+14B8h] [-8h]

  v26 = v19;
  v21 = 0;
  v20 = 0;
  memset(v19, 0, sizeof(v19));
  memset(v18, 0, sizeof(v18));
  v25 = v17;
  memset(v17, 0, sizeof(v17));
  v24 = httpd_get_parm(a1, "chack_new");
  v3 = nvram_get_int("ai_wx_wan_ping_pid1");
  v2 = nvram_get("ai_wx_ping_start_flag");
  if ( v2 )
    v4 = (const char *)v2;
  else
    v4 = "";
  v5 = httpd_get_parm(a1, "callback");
  v6 = v5;
  if ( v5 )
  {
    v7 = snprintf(v18, 1024, "%s(", v5);
    if ( v7 >= 0x400 )
      v7 = 1023;
    s = &v18[v7];
    v8 = 1024 - v7;
  }
  else
  {
    v8 = 1024;
    s = v18;
    v7 = 0;
  }
  if ( !kill(v3, 0) && v3 )
  {
LABEL_20:
    v13 = snprintf(s, v8, "{\"states\":\"0\"}");
    if ( v13 < v8 )
      goto LABEL_14;
    goto LABEL_21;
  }
  v23 = "a";
  if ( strcmp(v4, "1") )
    goto LABEL_19;
  v9 = v3;
  if ( !v24 )
    goto LABEL_13;
  if ( strcmp(v24, v23 + 9340) )
  {
LABEL_19:
    mkdir("/tmp/ai_wx_wan_ping", 0x1EDu);
    system("rm /tmp/ai_wx_wan_ping/* -rf");
    ai_ping_test((int)"114.114.114.114", (int)&v21);
    nvram_set_int("ai_wx_wan_ping_pid1", v21);
    nvram_set("ai_wx_ping_start_flag", v23 + 9340);
    goto LABEL_20;
  }
  v9 = v3;
LABEL_13:
  v10 = v26;
  sprintf(v26, "/tmp/ai_wx_wan_ping/ping_%d", v9);
  v11 = v25;
  v12 = f_read(v10, v25, 4096);
  v11[v12] = 0;
  ai_ping_check_file_status(v11, v12, &v20);
  nvram_set("ai_wx_ping_start_flag", "0");
  v13 = snprintf(s, v8, "{\"states\":\"%d\"}", v20);
  if ( v13 < v8 )
    goto LABEL_14;
LABEL_21:
  v13 = 1023 - v7;
LABEL_14:
  v14 = v7 + v13;
  if ( v6 )
  {
    v15 = snprintf(&v18[v14], 1024 - v14, ")");
    if ( v15 >= 1024 - v14 )
      v15 = 1023 - v14;
    v14 += v15;
  }
  return httpd_cgi_ret(a1, v18, v14, 4);
}
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A869C: using guessed type int __fastcall f_read(_DWORD, _DWORD, _DWORD);
// 6A878C: using guessed type int __fastcall nvram_set_int(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

