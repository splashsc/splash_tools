int __fastcall sub_4AF590(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s1
  const char **v5; // $v1
  const char *v6; // $v0
  const char *v7; // $t0
  const char *v8; // $a3
  const char *v9; // $a2
  const char *v10; // $a1
  int v11; // $a2
  unsigned int v13; // $v0
  int v14; // $a1
  const char *v15; // $a2
  const char *v16; // [sp+10h] [-490h]
  const char *v17; // [sp+20h] [-480h] BYREF
  const char *v18; // [sp+24h] [-47Ch]
  const char *v19; // [sp+28h] [-478h]
  int v20; // [sp+2Ch] [-474h]
  char v21[128]; // [sp+420h] [-80h] BYREF

  v3 = httpd_get_parm(a1, "opt");
  v2 = httpd_get_parm(a1, "device");
  if ( !v3 )
    goto LABEL_19;
  v4 = v2;
  if ( !strcmp(v3, "mount") )
  {
    if ( v4 )
    {
      if ( !strncmp(v4, "/dev/sd", 7u) )
      {
        v17 = "umount";
        v18 = "/tmp/mnt/sda1/";
        v19 = 0;
        eval(&v17, 0, 0, 0);
        v17 = "mount";
        v18 = v4;
        v19 = "/tmp/mnt/sda1/";
        v20 = 0;
        eval(&v17, 0, 0, 0);
      }
      else
      {
        v4 = "";
      }
      nvram_set("usb_mount_dev", v4);
      nvram_commit();
      goto LABEL_7;
    }
    goto LABEL_25;
  }
  if ( strcmp(v3, "mkfs") )
  {
    if ( !strcmp(v3, "umount") )
    {
      if ( v4 )
      {
        if ( !strcmp(v3, "umount") )
        {
          v17 = "umount";
          v18 = "/tmp/mnt/sda1/";
          v19 = 0;
          eval(&v17, 0, 0, 0);
        }
        goto LABEL_7;
      }
      goto LABEL_25;
    }
LABEL_19:
    v14 = *(unsigned __int8 *)(a1 + 210102);
    v15 = "not opt";
LABEL_20:
    v16 = (const char *)_GET_LANG_TEXT(12, v14, v15);
    v13 = snprintf((char *)&v17, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v16);
    goto LABEL_21;
  }
  if ( !v4 )
  {
LABEL_25:
    v14 = *(unsigned __int8 *)(a1 + 210102);
    v15 = (const char *)&unk_64DDD0;
    goto LABEL_20;
  }
  memset(v21, 0, sizeof(v21));
  if ( !mkfs_disk_device(*(unsigned __int8 *)(a1 + 210102), v4, v21, 128) )
  {
LABEL_7:
    v5 = &v17;
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
    v11 = 33;
    *(_WORD *)v5 = *(_WORD *)v6;
    return httpd_cgi_ret(a1, (char *)&v17, v11, 4);
  }
  v13 = snprintf((char *)&v17, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v21);
LABEL_21:
  v11 = v13;
  if ( v13 >= 0x400 )
    v11 = 1023;
  return httpd_cgi_ret(a1, (char *)&v17, v11, 4);
}
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8564: using guessed type int __fastcall mkfs_disk_device(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A87C4: using guessed type int nvram_commit(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

