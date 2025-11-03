# We need a debug build to access GDScript parse errors. Tools is for compiling the editor.
# Disabling 3D is only available in builds that exclude the editor (tools=no),
# it can be used for the final runtime/templates as Learn GDScript only uses 2D.
# Consider trying with LTO
scons target=debug \
	  tools=yes \
	  disable_3d=no \
	  module_arkit_enabled=no \
	  module_assimp_enabled=no \
	  module_bmp_enabled=no \
	  module_bullet_enabled=no \
	  module_camera_enabled=no \
	  module_csg_enabled=no \
	  module_dds_enabled=no \
	  module_enet_enabled=no \
	  module_etc_enabled=no \
	  module_gdnative_enabled=no \
	  module_gridmap_enabled=no \
	  module_hdr_enabled=no \
	  module_mbedtls_enabled=no \
	  module_mobile_vr_enabled=no \
	  module_opensimplex_enabled=no \
	  module_opus_enabled=no \
	  module_pvr_enabled=no \
	  module_recast_enabled=no \
	  module_squish_enabled=no \
	  module_tga_enabled=no \
	  module_theora_enabled=no \
	  module_tinyexr_enabled=no \
	  module_upnp_enabled=no \
	  module_vhacd_enabled=no \
	  module_vorbis_enabled=no \
	  module_webm_enabled=no \
	  module_webrtc_enabled=no \
	  module_websocket_enabled=no \
	  module_xatlas_unwrap_enabled=no \
