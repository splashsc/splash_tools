int __fastcall get_url_update_data(char *a1)
{
  const char *v2; // $s1
  const char *v3; // $s2
  const char *v4; // $v0

  v2 = (const char *)jhl_nv_get_def("url_update_en");
  v3 = (const char *)jhl_nv_get_def("url_update_path");
  v4 = (const char *)jhl_nv_get_def("url_update_time");
  return sprintf(a1, "\"enable\":\"%s\",\"srv_path\":\"%s\",\"mod_time\":\"%s\"", v2, v3, v4);
}
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

