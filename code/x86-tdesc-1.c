  static target_desc *amd64_linux_tdescs \
    [2/*AVX*/][2/*MPX*/][2/*AVX512*/][2/*PKRU*/] = {};
  static target_desc *x32_linux_tdescs[2/*AVX*/][2/*AVX512*/] = {};
  target_desc **tdesc;

  if (is_x32)
    {
      tdesc = &x32_linux_tdescs[(xcr0_features_bit & X86_XSTATE_AVX) ? 1 : 0 ]
	[(xcr0_features_bit & X86_XSTATE_AVX512) ? 1 : 0];
    }
  else
    {
      tdesc = &amd64_linux_tdescs[(xcr0_features_bit & X86_XSTATE_AVX) ? 1 : 0]
	[(xcr0_features_bit & X86_XSTATE_MPX) ? 1 : 0]
	[(xcr0_features_bit & X86_XSTATE_AVX512) ? 1 : 0]
	[(xcr0_features_bit & X86_XSTATE_PKRU) ? 1 : 0];
    }
  if (*tdesc == NULL)
    *tdesc = amd64_create_target_description (xcr0_features_bit, is_x32, true);
