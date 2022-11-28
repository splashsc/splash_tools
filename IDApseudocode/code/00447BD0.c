int __fastcall get_vlan_name_data(char *a1)
{
  bool v2; // dc
  char *v3; // $v0
  const char *v4; // $v0
  int v5; // $v0
  char *v6; // $v1
  char *v7; // $a0
  char *v8; // $v1
  char *v9; // $a0
  char *v10; // $v1
  char *v11; // $a0
  char *v12; // $v1
  char *v13; // $v1
  int v14; // $a1
  int v15; // $a0
  int result; // $v0
  char *v17; // $a0
  const char *v18; // $v1
  int v19; // $a0
  int v20; // $a1
  int v21; // $a0
  char v22; // $a1
  char v23; // $a0
  char v24; // $v1

  v2 = sq_file_get_jb() == 0;
  v3 = a1;
  if ( v2 )
  {
    v18 = "\"vlan_name\":\"L123456789\",\"vlan_wans\":[{\"lab\":\"1\",\"v\":\"L123456789\"}";
    do
    {
      v19 = *((_DWORD *)v18 + 1);
      *(_DWORD *)v3 = *(_DWORD *)v18;
      *((_DWORD *)v3 + 1) = v19;
      v20 = *((_DWORD *)v18 + 2);
      *((_DWORD *)v3 + 1) = v19;
      *((_DWORD *)v3 + 2) = v20;
      v21 = *((_DWORD *)v18 + 3);
      *((_DWORD *)v3 + 2) = v20;
      *((_DWORD *)v3 + 3) = v21;
      v18 += 16;
      *((_DWORD *)v3 + 3) = v21;
      v3 += 16;
    }
    while ( v18 != "\"}" );
    v22 = *v18;
    v23 = v18[1];
    v24 = v18[2];
    *v3 = v22;
    v3[1] = v23;
    v3[2] = v24;
    v15 = 67;
    result = 83;
    v14 = 66;
  }
  else
  {
    v4 = (const char *)nvram_get("vlan_name_old");
    if ( !v4 )
    {
      v4 = (const char *)nvram_get("vlan_name");
      if ( !v4 )
        v4 = "L1";
    }
    v5 = sprintf(a1, "\"vlan_name\":\"%s\",\"vlan_wans\":[", v4);
    strcpy(&a1[v5], "{\"lab\":\"1\",\"v\":\"L123456789\"},");
    qmemcpy(&a1[v5], "{\"lab\":\"1\",\"v\":\"L123", 20);
    v6 = &a1[v5 + 29];
    *(_DWORD *)&a1[v5 + 24] = 2099394872;
    strcpy(v6, "{\"lab\":\"2\",\"v\":\"L12345678\"},");
    *(_DWORD *)v6 = 1634476667;
    *((_DWORD *)v6 + 1) = 574235234;
    v7 = &a1[v5 + 57];
    *((_DWORD *)v6 + 6) = 746398264;
    strcpy(v7, "{\"lab\":\"3\",\"v\":\"L1234567\"},");
    *((_DWORD *)v7 + 5) = 926299444;
    v8 = &a1[v5 + 84];
    strcpy(v8, "{\"lab\":\"4\",\"v\":\"L123456\"},");
    qmemcpy(v8, "{\"lab\":\"4\",\"v\":\"", 16);
    v9 = &a1[v5 + 110];
    *((_DWORD *)v8 + 5) = 573977908;
    strcpy(v9, "{\"lab\":\"5\",\"v\":\"L12345\"},");
    qmemcpy(v9, "{\"lab\":\"5\",\"", 12);
    *((_DWORD *)v9 + 4) = 858927436;
    v10 = &a1[v5 + 135];
    *((_DWORD *)v9 + 5) = 2099393844;
    strcpy(v10, "{\"lab\":\"6\",\"v\":\"L1234\"},");
    *(_DWORD *)v10 = *(_DWORD *)"{\"lab\":\"6\",\"v\":\"L1234\"},";
    qmemcpy(v10 + 16, "L1234\"},", 8);
    v11 = &a1[v5 + 159];
    strcpy(v11, "{\"lab\":\"7\",\"v\":\"L123\"},");
    v12 = &a1[v5 + 182];
    strcpy(v11 + 20, "\"},");
    strcpy(v12, "{\"lab\":\"8\",\"v\":\"L12\"},");
    *((_DWORD *)v12 + 3) = 574235254;
    v13 = &a1[v5 + 204];
    strcpy(v13, "{\"lab\":\"9\",\"v\":\"L1\"}");
    qmemcpy(v13, "{\"lab\":\"9\",\"v\":\"", 16);
    v14 = v5 + 224;
    v15 = v5 + 225;
    result = v5 + 241;
  }
  *(_WORD *)&a1[v14] = 93;
  v17 = &a1[v15];
  strcpy(v17, ",\"port_max\":\"10\"");
  qmemcpy(v17, ",\"port_max\":", 12);
  return result;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A85E4: using guessed type int sq_file_get_jb(void);

