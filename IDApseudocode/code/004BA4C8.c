ssize_t shenji_ctrl_set_en()
{
  const char *v0; // $s0

  v0 = (const char *)jhl_nv_get_def("sj_en");
  nvram_set("sj_state_en", v0);
  return shenji_send_to_ctrl(v0);
}
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

