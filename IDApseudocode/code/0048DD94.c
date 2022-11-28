int show_ipsec_status()
{
  int v0; // $v0
  const char *v1; // $s0
  int v2; // $s3
  char *v4; // $v1
  const char *v5; // $v0
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  int v9; // $a1
  int v10; // $a2
  int v11; // $a1
  int v12; // $v0
  int v13; // $s2
  ssize_t v14; // $s1
  char *v15; // $a0
  void *v16; // $v0
  char *v17; // $s0
  int v18; // $s4
  int v19; // $s1
  int v20; // $s2
  int v21; // $s5
  char *v22; // $s6
  char v23; // $v0
  const char *v24; // $s6
  int v25; // $s6
  int v26; // $s2
  int v27; // $s1
  int v28; // $s7
  ssize_t v29; // $fp
  char *v30; // $v0
  int v31; // $v0
  int v32; // $s7
  int v33; // $a2
  char *v34; // $fp
  char *v35; // $v0
  char *v36; // $v1
  int v37; // $a0
  int v38; // $v1
  void *v39; // $v0
  void *v40; // $s1
  int v41; // $v0
  int v42; // $s0
  char v43[1032]; // [sp+20h] [-560h] BYREF
  struct stat v44; // [sp+428h] [-158h] BYREF
  const char *v45; // [sp+4C8h] [-B8h] BYREF
  char *v46; // [sp+4DCh] [-A4h]
  const char *v47; // [sp+4F4h] [-8Ch]
  char v48[24]; // [sp+540h] [-40h] BYREF
  int v49; // [sp+558h] [-28h]
  char *v50; // [sp+55Ch] [-24h]
  char *v51; // [sp+560h] [-20h]
  int v52; // [sp+564h] [-1Ch]
  void *v53; // [sp+568h] [-18h]
  char *format; // [sp+56Ch] [-14h]
  char *v55; // [sp+570h] [-10h]
  char *v56; // [sp+574h] [-Ch]
  char *v57; // [sp+578h] [-8h]

  v0 = nvram_get("ipsec_mode");
  if ( !v0 )
  {
    memset(ipsec_info, 0, sizeof(ipsec_info));
    return 1;
  }
  v1 = (const char *)v0;
  memset(ipsec_info, 0, sizeof(ipsec_info));
  if ( !strcmp(v1, "net") )
  {
    v55 = "1\"";
    _mem_malloc(76800, "show_ipsec_status", 998);
    v53 = v16;
    if ( !v16 )
      return 1;
    jhl_parm_get("ipsec_net_users", v53, 76799);
    jhl_system("setkey -Ds >/tmp/sadump");
    jhl_system("setkey -DPs >/tmp/spdump");
    if ( stat("/tmp/sadump", &v44)
      || *(_QWORD *)&v44.st_atim < 11
      || (_mem_malloc(v44.st_atim.tv_sec + 4, v55 - 18508, 1008), v40 = v39, (v51 = (char *)v39) == 0) )
    {
      v17 = v43;
      v18 = split_string(v53, 60, v43, 256);
      if ( v18 <= 0 )
      {
        _mem_free(v53);
        return 1;
      }
      v50 = 0;
      v51 = 0;
    }
    else
    {
      v41 = open("/tmp/sadump", 0);
      v42 = v41;
      if ( v41 < 0 )
      {
        v50 = 0;
      }
      else
      {
        v50 = (char *)read(v41, v40, v44.st_atim.tv_sec);
        close(v42);
      }
      v17 = v43;
      v18 = split_string(v53, 60, v43, 256);
      if ( v18 <= 0 )
      {
        _mem_free(v53);
        v2 = 1;
        goto LABEL_27;
      }
    }
    v49 = (int)ipsec_info;
    format = "%s";
    v19 = 0;
    v56 = "dynamic";
    v2 = 1;
    v20 = 0;
    v57 = "%s(%s)";
    do
    {
      if ( split_string(*(_DWORD *)v17, 124, &v45, 30) >= 25 )
      {
        v21 = 65 * v20;
        v22 = (char *)(v49 + 65 * v20);
        snprintf(v22, 32, "%s", v45);
        v52 = (int)ipsec_info;
        if ( v50 )
        {
          v52 = (int)v48;
          v23 = GetIpsecSaStatus(v51, v46, v47, v48, 0x16u);
          v22[64] = v23;
          v24 = v46;
          if ( v23 && !strcmp(v46, v56) )
          {
            snprintf(&ipsec_info[v21 + 32], 32, v57, v24, v52);
            ++v20;
          }
          else
          {
            snprintf((char *)(v49 + 65 * v20++ + 32), 32, "%s", v24);
          }
        }
        else
        {
          snprintf(&ipsec_info[v21 + 32], 32, format, v46);
          ++v20;
        }
        v2 = 0;
        if ( v20 == 256 )
          break;
      }
      ++v19;
      v17 += 4;
    }
    while ( v19 < v18 );
    _mem_free(v53);
    if ( !v51 )
      return v2;
LABEL_27:
    _mem_free(v51);
    return v2;
  }
  v2 = strcmp(v1, "road");
  if ( v2 )
    return 1;
  memset(v43, 0, 0x200u);
  v4 = v43;
  v5 = "racoonctl -s /var/run/racoon.sock show-sa isakmp |wc -l >/etc/racoon/tmp123";
  do
  {
    v6 = *(_DWORD *)v5;
    v7 = *((_DWORD *)v5 + 1);
    v8 = *((_DWORD *)v5 + 2);
    v9 = *((_DWORD *)v5 + 3);
    v5 += 16;
    *(_DWORD *)v4 = v6;
    *((_DWORD *)v4 + 1) = v7;
    *((_DWORD *)v4 + 2) = v8;
    *((_DWORD *)v4 + 3) = v9;
    v4 += 16;
  }
  while ( v5 != "coon/tmp123" );
  v10 = *(_DWORD *)v5;
  v11 = *((_DWORD *)v5 + 1);
  v12 = *((_DWORD *)v5 + 2);
  *((_DWORD *)v4 + 1) = v11;
  *(_DWORD *)v4 = v10;
  *((_DWORD *)v4 + 2) = v12;
  jhl_system(v43);
  v13 = open("/etc/racoon/tmp123", 0);
  if ( v13 < 0 )
    return 1;
  memset(v43, 0, 0x200u);
  v14 = read(v13, v43, 0x20u);
  close(v13);
  if ( v14 <= 0 )
    return 1;
  v15 = v43;
  while ( (unsigned int)(*v15 - 48) >= 0xA )
  {
    if ( &v43[v14] == ++v15 )
      return 1;
  }
  v25 = J_atoi(v15);
  if ( v25 < 2 )
    return 1;
  v51 = "1\"";
  v49 = 1;
  v26 = 0;
  v27 = 2;
  v50 = ipsec_info;
  v52 = 1684107090;
  do
  {
    memset(v43, 0, 0x200u);
    sprintf(
      v43,
      "racoonctl -s /var/run/racoon.sock show-sa isakmp |sed -n '%dp' |sed 's/\\(.*\\)\\.\\(.*\\)\\.\\(.*\\)\\.\\(.*\\)\\"
      ".\\(.*\\) .*/\\1.\\2.\\3.\\4/' >/etc/racoon/tmp123",
      v27);
    jhl_system(v43);
    v28 = open("/etc/racoon/tmp123", 0);
    if ( v28 >= 0 )
    {
      memset(v43, 0, 0x200u);
      v29 = read(v28, v43, 0x20u);
      close(v28);
      if ( v29 >= 2 )
      {
        v30 = strchr(v43, 13);
        if ( v30 || (v30 = strchr(v43, 10)) != 0 )
        {
          v29 = v30 - v43;
          v31 = v26 << 6;
        }
        else
        {
          v31 = v26 << 6;
        }
        v32 = v31 + v26;
        v33 = v29;
        v34 = v50;
        memcpy(&v50[v31 + 32 + v26], v43, v33);
        v35 = &v34[v32];
        v36 = v51 - 19816;
        v37 = *((_DWORD *)v51 - 4953);
        *(_DWORD *)v35 = v52;
        *((_DWORD *)v35 + 1) = v37;
        v38 = *((_DWORD *)v36 + 2);
        *((_DWORD *)v35 + 1) = v37;
        *((_DWORD *)v35 + 2) = v38;
        ++v26;
        v35[64] = 1;
        if ( v26 == 256 )
          return v2;
        v49 = 0;
      }
    }
    ++v27;
  }
  while ( v25 >= v27 );
  return v49;
}
// 48DFC4: variable 'v16' is possibly undefined
// 48E4A4: variable 'v39' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8594: using guessed type int __fastcall jhl_system(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

