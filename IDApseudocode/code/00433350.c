int __fastcall usb_httpd_passwd_md5(char *a1, const char *a2)
{
  const char *v4; // $v0
  const char *v5; // $s3
  int v6; // $s3
  char v8[256]; // [sp+50h] [-16Ch] BYREF
  unsigned int v9[22]; // [sp+150h] [-6Ch] BYREF
  unsigned __int8 v10; // [sp+1A8h] [-14h]
  unsigned __int8 v11; // [sp+1A9h] [-13h]
  unsigned __int8 v12; // [sp+1AAh] [-12h]
  unsigned __int8 v13; // [sp+1ABh] [-11h]
  unsigned __int8 v14; // [sp+1ACh] [-10h]
  unsigned __int8 v15; // [sp+1ADh] [-Fh]
  unsigned __int8 v16; // [sp+1AEh] [-Eh]
  unsigned __int8 v17; // [sp+1AFh] [-Dh]
  unsigned __int8 v18; // [sp+1B0h] [-Ch]
  unsigned __int8 v19; // [sp+1B1h] [-Bh]
  unsigned __int8 v20; // [sp+1B2h] [-Ah]
  unsigned __int8 v21; // [sp+1B3h] [-9h]
  unsigned __int8 v22; // [sp+1B4h] [-8h]
  unsigned __int8 v23; // [sp+1B5h] [-7h]
  unsigned __int8 v24; // [sp+1B6h] [-6h]
  unsigned __int8 v25; // [sp+1B7h] [-5h]

  memset(v8, 0, sizeof(v8));
  v5 = (const char *)custom_device_name();
  v4 = (const char *)get_sn();
  v6 = snprintf(v8, 256, "%s%s%susb", v5, a2, v4);
  FBR_MD5Init(v9);
  FBR_MD5Update(v9, (int)v8, v6);
  FBR_MD5Final(v9);
  return sprintf(
           a1,
           "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
           v10,
           v13,
           v12,
           v11,
           v14,
           v17,
           v16,
           v15,
           v20,
           v19,
           v18,
           v21,
           v25,
           v23,
           v24,
           v22);
}
// 6A81D8: using guessed type int get_sn(void);
// 6A86E4: using guessed type int custom_device_name(void);

