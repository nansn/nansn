#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x2879b7e6, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x5e25804, __VMLINUX_SYMBOL_STR(__request_region) },
	{ 0x8cba24db, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x531d12bf, __VMLINUX_SYMBOL_STR(dma_release_from_dev_coherent) },
	{ 0xf33847d3, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x1ba6b410, __VMLINUX_SYMBOL_STR(uart_write_wakeup) },
	{ 0x9439f5c3, __VMLINUX_SYMBOL_STR(pci_write_config_word) },
	{ 0x2e655c34, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x110b5cbf, __VMLINUX_SYMBOL_STR(uart_add_one_port) },
	{ 0xc364ae22, __VMLINUX_SYMBOL_STR(iomem_resource) },
	{ 0xe08ba8c4, __VMLINUX_SYMBOL_STR(pci_disable_device) },
	{ 0x92fcf04b, __VMLINUX_SYMBOL_STR(uart_handle_cts_change) },
	{ 0xf88dc79c, __VMLINUX_SYMBOL_STR(uart_get_divisor) },
	{ 0x2111135f, __VMLINUX_SYMBOL_STR(uart_unregister_driver) },
	{ 0xf18427f1, __VMLINUX_SYMBOL_STR(pci_enable_wake) },
	{ 0x77733557, __VMLINUX_SYMBOL_STR(uart_update_timeout) },
	{ 0x3146a3cb, __VMLINUX_SYMBOL_STR(uart_remove_one_port) },
	{ 0x68054716, __VMLINUX_SYMBOL_STR(dma_alloc_from_dev_coherent) },
	{ 0x64b94956, __VMLINUX_SYMBOL_STR(pci_set_master) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xda0c09bf, __VMLINUX_SYMBOL_STR(__tty_insert_flip_char) },
	{ 0x150ad92b, __VMLINUX_SYMBOL_STR(ioport_resource) },
	{ 0xb69d9c0f, __VMLINUX_SYMBOL_STR(pci_restore_state) },
	{ 0x506e327d, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x97fdbab9, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x4767c562, __VMLINUX_SYMBOL_STR(do_SAK) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xfadf2436, __VMLINUX_SYMBOL_STR(memstart_addr) },
	{ 0x7b525061, __VMLINUX_SYMBOL_STR(pci_read_config_word) },
	{ 0x360ff19f, __VMLINUX_SYMBOL_STR(down) },
	{ 0xd6b8e852, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0xf24b3dfe, __VMLINUX_SYMBOL_STR(__ioremap) },
	{ 0xc3818d6f, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0xaf81a107, __VMLINUX_SYMBOL_STR(uart_handle_dcd_change) },
	{ 0xe85db0a1, __VMLINUX_SYMBOL_STR(cpu_hwcaps) },
	{ 0x1ae8d0f9, __VMLINUX_SYMBOL_STR(cpu_hwcap_keys) },
	{ 0x8d15114a, __VMLINUX_SYMBOL_STR(__release_region) },
	{ 0x79d89b50, __VMLINUX_SYMBOL_STR(pci_unregister_driver) },
	{ 0x5cd885d5, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xd2d19322, __VMLINUX_SYMBOL_STR(dummy_dma_ops) },
	{ 0x96220280, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x3c578bac, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xb4b8d4ea, __VMLINUX_SYMBOL_STR(pci_set_power_state) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x324b3877, __VMLINUX_SYMBOL_STR(up) },
	{ 0xf71650f4, __VMLINUX_SYMBOL_STR(__pci_register_driver) },
	{ 0x4c09e7cc, __VMLINUX_SYMBOL_STR(uart_register_driver) },
	{ 0x45a55ec8, __VMLINUX_SYMBOL_STR(__iounmap) },
	{ 0x88e0d9cd, __VMLINUX_SYMBOL_STR(tty_flip_buffer_push) },
	{ 0x9b6565a9, __VMLINUX_SYMBOL_STR(pci_enable_device) },
	{ 0x9ee37840, __VMLINUX_SYMBOL_STR(arm64_const_caps_ready) },
	{ 0x4c8be882, __VMLINUX_SYMBOL_STR(uart_get_baud_rate) },
	{ 0x820c8158, __VMLINUX_SYMBOL_STR(uart_insert_char) },
	{ 0xc1514a3b, __VMLINUX_SYMBOL_STR(free_irq) },
	{ 0x6787d4c3, __VMLINUX_SYMBOL_STR(pci_save_state) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

