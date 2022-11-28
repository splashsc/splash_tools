int __fastcall reset_sj_param(char a1)
{
  int v2; // $v0
  char *v3; // $s4
  char *v4; // $s3
  char *v5; // $s2
  int v6; // $a0
  int v7; // $v0
  int v8; // $s0
  int v10; // $a1
  int v11; // $a1
  int v12; // $a1
  int v13; // $a1
  int v14; // $a1
  int v15; // $a1
  int v16; // $a1
  int v17; // $v0
  int v18; // $v0
  int v19; // $v0
  int v20; // $a1
  int v21; // $a1
  int v22; // $a1
  int v23; // $a1
  int v24; // $a1
  int v25; // $a1
  int v26; // $a1
  int v27; // $a1
  int v28; // $a1
  int v29; // $a1
  int v30; // $a1
  int v31; // $a1
  int v32; // $a1
  int v33; // $a1
  int v34; // $a1
  int v35; // $a1
  int v36; // $a1
  int v37; // $a1
  int v38; // $a1
  int v39; // $a1
  int v40; // $a1
  int v41; // $a1
  int v42; // $a1
  int v43; // $a1
  int v44; // $a1
  int v45; // $a1
  int v46; // $a1
  int v47; // $a1
  int v48; // $a1
  int v49; // $a1
  int v50; // $a1
  int v51; // $a1
  int v52; // $a1
  int v53; // $a1
  int v54; // $a1
  int v55; // $a1
  int v56; // $a1
  int v57; // $a1
  int v58; // $a1
  int v59; // $a1
  int v60; // $a1
  int v61; // $a1
  int v62; // $a1
  int v63; // $a1
  int v64; // $a1
  int v65; // $a1
  int v66; // $a1
  int v67; // $a1
  int v68; // $a1
  int v69; // $a1
  int v70; // $a1
  int v71; // $a1

  v2 = nvram_get("sj_palce_num");
  if ( v2 )
    v3 = (char *)v2;
  else
    v3 = "";
  v4 = (char *)nvram_get("sj_palce_code");
  if ( !v4 )
    v4 = "";
  v5 = (char *)nvram_get("sj_palce_num_dst");
  if ( !v5 )
    v5 = "";
  nvram_set("sj_palce_num_backup", v3);
  nvram_set("sj_palce_code_backup", v4);
  nvram_set("sj_palce_num_dst_backup", v5);
  nvram_set("sj_real_dev_sn", "");
  nvram_set("sj_real_tz_sn", "");
  v7 = a1 & 2;
  if ( (a1 & 1) != 0 )
  {
    v54 = jhl_nv_get_only_def("sj_dev_sn");
    if ( v54 )
      nvram_set("sj_dev_sn", v54);
    else
      nvram_unset("sj_dev_sn");
    v55 = jhl_nv_get_only_def("sj_dev_name");
    if ( v55 )
      nvram_set("sj_dev_name", v55);
    else
      nvram_unset("sj_dev_name");
    v56 = jhl_nv_get_only_def("sj_dev_addr");
    if ( v56 )
      nvram_set("sj_dev_addr", v56);
    else
      nvram_unset("sj_dev_addr");
    v57 = jhl_nv_get_only_def("sj_dev_type");
    if ( v57 )
      nvram_set("sj_dev_type", v57);
    else
      nvram_unset("sj_dev_type");
    v58 = jhl_nv_get_only_def("sj_dev_lable");
    if ( v58 )
      nvram_set("sj_dev_lable", v58);
    else
      nvram_unset("sj_dev_lable");
    v59 = jhl_nv_get_only_def("sj_fixed_type");
    if ( v59 )
      nvram_set("sj_fixed_type", v59);
    else
      nvram_unset("sj_fixed_type");
    v60 = jhl_nv_get_only_def("sj_dev_longitude");
    if ( v60 )
      nvram_set("sj_dev_longitude", v60);
    else
      nvram_unset("sj_dev_longitude");
    v61 = jhl_nv_get_only_def("sj_dev_latitude");
    if ( v61 )
      nvram_set("sj_dev_latitude", v61);
    else
      nvram_unset("sj_dev_latitude");
    v62 = jhl_nv_get_only_def("sj_jwd_type");
    if ( v62 )
      nvram_set("sj_jwd_type", v62);
    else
      nvram_unset("sj_jwd_type");
    v63 = jhl_nv_get_only_def("sj_dev_interval_time");
    if ( v63 )
      nvram_set("sj_dev_interval_time", v63);
    else
      nvram_unset("sj_dev_interval_time");
    v64 = jhl_nv_get_only_def("sj_dev_radius");
    if ( v64 )
      nvram_set("sj_dev_radius", v64);
    else
      nvram_unset("sj_dev_radius");
    v65 = jhl_nv_get_only_def("sj_dev_floor");
    if ( v65 )
      nvram_set("sj_dev_floor", v65);
    else
      nvram_unset("sj_dev_floor");
    v66 = jhl_nv_get_only_def("sj_dev_station");
    if ( v66 )
      nvram_set("sj_dev_station", v66);
    else
      nvram_unset("sj_dev_station");
    v67 = jhl_nv_get_only_def("sj_dev_car_num");
    if ( v67 )
      nvram_set("sj_dev_car_num", v67);
    else
      nvram_unset("sj_dev_car_num");
    v68 = jhl_nv_get_only_def("sj_dev_metro");
    if ( v68 )
      nvram_set("sj_dev_metro", v68);
    else
      nvram_unset("sj_dev_metro");
    v69 = jhl_nv_get_only_def("sj_dev_metro_car");
    if ( v69 )
      nvram_set("sj_dev_metro_car", v69);
    else
      nvram_unset("sj_dev_metro_car");
    v70 = jhl_nv_get_only_def("sj_dev_metro_box");
    if ( v70 )
      nvram_set("sj_dev_metro_box", v70);
    else
      nvram_unset("sj_dev_metro_box");
    v71 = jhl_nv_get_only_def("sj_aps_list");
    if ( v71 )
      nvram_set("sj_aps_list", v71);
    else
      nvram_unset("sj_aps_list");
    v7 = a1 & 2;
  }
  if ( v7 )
  {
    v17 = jhl_nv_get_only_def("sj_palce_num_dst");
    if ( v17 )
      nvram_set("sj_palce_num_dst", v17);
    else
      nvram_unset("sj_palce_num_dst");
    v18 = jhl_nv_get_only_def("sj_palce_num");
    if ( v18 )
      nvram_set("sj_palce_num", v18);
    else
      nvram_unset("sj_palce_num");
    v19 = jhl_nv_get_only_def("sj_palce_code");
    if ( v19 )
      nvram_set("sj_palce_code", v19);
    else
      nvram_unset("sj_palce_code");
    v20 = jhl_nv_get_only_def("sj_palce_name");
    if ( v20 )
      nvram_set("sj_palce_name", v20);
    else
      nvram_unset("sj_palce_name");
    v21 = jhl_nv_get_only_def("sj_place_uscc");
    if ( v21 )
      nvram_set("sj_place_uscc", v21);
    else
      nvram_unset("sj_place_uscc");
    v22 = jhl_nv_get_only_def("sj_palce_addr");
    if ( v22 )
      nvram_set("sj_palce_addr", v22);
    else
      nvram_unset("sj_palce_addr");
    v23 = jhl_nv_get_only_def("sj_palce_state");
    if ( v23 )
      nvram_set("sj_palce_state", v23);
    else
      nvram_unset("sj_palce_state");
    v24 = jhl_nv_get_only_def("sj_palce_longitude");
    if ( v24 )
      nvram_set("sj_palce_longitude", v24);
    else
      nvram_unset("sj_palce_longitude");
    v25 = jhl_nv_get_only_def("sj_palce_latitude");
    if ( v25 )
      nvram_set("sj_palce_latitude", v25);
    else
      nvram_unset("sj_palce_latitude");
    v26 = jhl_nv_get_only_def("sj_palce_nature");
    if ( v26 )
      nvram_set("sj_palce_nature", v26);
    else
      nvram_unset("sj_palce_nature");
    v27 = jhl_nv_get_only_def("sj_palce_worker");
    if ( v27 )
      nvram_set("sj_palce_worker", v27);
    else
      nvram_unset("sj_palce_worker");
    v28 = jhl_nv_get_only_def("sj_palce_worker_cardtype");
    if ( v28 )
      nvram_set("sj_palce_worker_cardtype", v28);
    else
      nvram_unset("sj_palce_worker_cardtype");
    v29 = jhl_nv_get_only_def("sj_palce_worker_cardid");
    if ( v29 )
      nvram_set("sj_palce_worker_cardid", v29);
    else
      nvram_unset("sj_palce_worker_cardid");
    v30 = jhl_nv_get_only_def("sj_palce_phone");
    if ( v30 )
      nvram_set("sj_palce_phone", v30);
    else
      nvram_unset("sj_palce_phone");
    v31 = jhl_nv_get_only_def("sj_palce_start_time");
    if ( v31 )
      nvram_set("sj_palce_start_time", v31);
    else
      nvram_unset("sj_palce_start_time");
    v32 = jhl_nv_get_only_def("sj_palce_end_time");
    if ( v32 )
      nvram_set("sj_palce_end_time", v32);
    else
      nvram_unset("sj_palce_end_time");
    v33 = jhl_nv_get_only_def("sj_dev_sid");
    if ( v33 )
      nvram_set("sj_dev_sid", v33);
    else
      nvram_unset("sj_dev_sid");
    v34 = jhl_nv_get_only_def("sj_network_type");
    if ( v34 )
      nvram_set("sj_network_type", v34);
    else
      nvram_unset("sj_network_type");
    v35 = jhl_nv_get_only_def("sj_debug_log");
    if ( v35 )
      nvram_set("sj_debug_log", v35);
    else
      nvram_unset("sj_debug_log");
    v36 = jhl_nv_get_only_def("sj_netsite_type");
    if ( v36 )
      nvram_set("sj_netsite_type", v36);
    else
      nvram_unset("sj_netsite_type");
    v37 = jhl_nv_get_only_def("sj_business_nature");
    if ( v37 )
      nvram_set("sj_business_nature", v37);
    else
      nvram_unset("sj_business_nature");
    v38 = jhl_nv_get_only_def("sj_access_type");
    if ( v38 )
      nvram_set("sj_access_type", v38);
    else
      nvram_unset("sj_access_type");
    v39 = jhl_nv_get_only_def("sj_operator_net");
    if ( v39 )
      nvram_set("sj_operator_net", v39);
    else
      nvram_unset("sj_operator_net");
    v40 = jhl_nv_get_only_def("sj_terminal_netenv");
    if ( v40 )
      nvram_set("sj_terminal_netenv", v40);
    else
      nvram_unset("sj_terminal_netenv");
    v41 = jhl_nv_get_only_def("sj_acsses_ip_auth_account");
    if ( v41 )
      nvram_set("sj_acsses_ip_auth_account", v41);
    else
      nvram_unset("sj_acsses_ip_auth_account");
    v42 = jhl_nv_get_only_def("sj_data_caiji_type");
    if ( v42 )
      nvram_set("sj_data_caiji_type", v42);
    else
      nvram_unset("sj_data_caiji_type");
    v43 = jhl_nv_get_only_def("sj_caiji_type");
    if ( v43 )
      nvram_set("sj_caiji_type", v43);
    else
      nvram_unset("sj_caiji_type");
    v44 = jhl_nv_get_only_def("sj_ssq_type");
    if ( v44 )
      nvram_set("sj_ssq_type", v44);
    else
      nvram_unset("sj_ssq_type");
    v45 = jhl_nv_get_only_def("sj_province_name");
    if ( v45 )
      nvram_set("sj_province_name", v45);
    else
      nvram_unset("sj_province_name");
    v46 = jhl_nv_get_only_def("sj_city_name");
    if ( v46 )
      nvram_set("sj_city_name", v46);
    else
      nvram_unset("sj_city_name");
    v47 = jhl_nv_get_only_def("sj_area_name");
    if ( v47 )
      nvram_set("sj_area_name", v47);
    else
      nvram_unset("sj_area_name");
    v48 = jhl_nv_get_only_def("sj_police_code");
    if ( v48 )
      nvram_set("sj_police_code", v48);
    else
      nvram_unset("sj_police_code");
    v49 = jhl_nv_get_only_def("sj_fz_name");
    if ( v49 )
      nvram_set("sj_fz_name", v49);
    else
      nvram_unset("sj_fz_name");
    v50 = jhl_nv_get_only_def("sj_fz_cardid");
    if ( v50 )
      nvram_set("sj_fz_cardid", v50);
    else
      nvram_unset("sj_fz_cardid");
    v51 = jhl_nv_get_only_def("sj_fz_phone");
    if ( v51 )
      nvram_set("sj_fz_phone", v51);
    else
      nvram_unset("sj_fz_phone");
    v52 = jhl_nv_get_only_def("sj_dev_caiji_class");
    if ( v52 )
      nvram_set("sj_dev_caiji_class", v52);
    else
      nvram_unset("sj_dev_caiji_class");
    v53 = jhl_nv_get_only_def("sj_caiji_company");
    if ( v53 )
      nvram_set("sj_caiji_company", v53);
    else
      nvram_unset("sj_caiji_company");
    v8 = a1 & 8;
  }
  else
  {
    v8 = a1 & 8;
  }
  if ( v8 )
  {
    v10 = jhl_nv_get_only_def("sj_company_name");
    if ( v10 )
      nvram_set("sj_company_name", v10);
    else
      nvram_unset("sj_company_name");
    v11 = jhl_nv_get_only_def("sj_company_code");
    if ( v11 )
      nvram_set("sj_company_code", v11);
    else
      nvram_unset("sj_company_code");
    v12 = jhl_nv_get_only_def("sj_company_uscc");
    if ( v12 )
      nvram_set("sj_company_uscc", v12);
    else
      nvram_unset("sj_company_uscc");
    v13 = jhl_nv_get_only_def("sj_company_addr");
    if ( v13 )
      nvram_set("sj_company_addr", v13);
    else
      nvram_unset("sj_company_addr");
    v14 = jhl_nv_get_only_def("sj_company_people");
    if ( v14 )
      nvram_set("sj_company_people", v14);
    else
      nvram_unset("sj_company_people");
    v15 = jhl_nv_get_only_def("sj_company_phone");
    if ( v15 )
      nvram_set("sj_company_phone", v15);
    else
      nvram_unset("sj_company_phone");
    v16 = jhl_nv_get_only_def("sj_company_email");
    if ( v16 )
      nvram_set("sj_company_email", v16);
    else
      nvram_unset("sj_company_email");
  }
  jhl_parm_commit(v6);
  return 0;
}
// 4B6340: variable 'v6' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A86F4: using guessed type int __fastcall jhl_nv_get_only_def(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

