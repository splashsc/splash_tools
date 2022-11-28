int __fastcall sub_4C4B88(int a1, int a2, const char *a3)
{
  int v6; // $v0
  int v7; // $v0
  const char *v8; // $s2
  int v9; // $v0
  const char *v10; // $s3
  int v11; // $v0
  const char *v12; // $s4
  int v13; // $v0
  const char *v14; // $s5
  int v15; // $v0
  const char *v16; // $v1
  int v17; // $v0
  const char *v18; // $v0
  char v20[32]; // [sp+38h] [-28h] BYREF
  const char *v21; // [sp+58h] [-8h]

  snprintf(v20, 32, "LAN%u", a2 + 1);
  v6 = lan_name_get2("ipv6.lan", a2, "ip", 0);
  v7 = nvram_get(v6);
  if ( v7 )
    v8 = (const char *)v7;
  else
    v8 = "";
  v9 = lan_name_get2("ipv6.lan", a2, &unk_4D0FF8, 0);
  v10 = (const char *)nvram_get(v9);
  if ( !v10 )
    v10 = "";
  v11 = lan_name_get2("ipv6.lan", a2, "dhcp", 0);
  v12 = (const char *)nvram_get(v11);
  if ( !v12 )
    v12 = "";
  v13 = lan_name_get2("ipv6.lan", a2, "ndp", 0);
  v14 = (const char *)nvram_get(v13);
  if ( !v14 )
    v14 = "";
  v15 = lan_name_get2("ipv6.lan", a2, &off_6508E4, 0);
  v16 = (const char *)nvram_get(v15);
  if ( !v16 )
    v16 = "";
  v21 = v16;
  v17 = lan_name_get2("ipv6.lan", a2, "dns", 0);
  v18 = (const char *)nvram_get(v17);
  if ( !v18 )
    v18 = "";
  mcl_bytearray_printf(
    a1,
    "{\"iface\":\"%u\",\"ifname\":\"%s\",\"showname\":\"%s\",\"ip\":\"%s\",\"ra_type\":\"%s\",\"dhcp_type\":\"%s\",\"ndp_"
    "type\":\"%s\",\"ula\":\"%s\",\"dns\":\"%s\"},",
    a2,
    a3,
    v20,
    v8,
    v10,
    v12,
    v14,
    v21,
    v18);
  return -1;
}
// 6508E4: using guessed type void *off_6508E4;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8414: using guessed type int mcl_bytearray_printf(_DWORD, const char *, ...);
// 6A84C4: using guessed type int __fastcall lan_name_get2(_DWORD, _DWORD, _DWORD, _DWORD);

