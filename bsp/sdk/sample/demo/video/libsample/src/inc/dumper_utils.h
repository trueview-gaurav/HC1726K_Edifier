#ifndef DUMPER_UTILS_H
#define DUMPER_UTILS_H

#include <stdbool.h>
#include <linux/limits.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Prefix that triggers sdcard readiness check.
 * Paths with this prefix are treated as removable (may be unready at boot).
 */
#define DUMPER_SDCARD_PREFIX "/mnt/"

/**
 * Fallback dir when target mount isn’t ready.
 * Must be an always-available writable tmpfs (e.g., /tmp).
 */
#define DUMPER_FALLBACK_DIR "/tmp"

/**
 * Check if dir is writable and usable (as-is, no path translation).
 * Verifies: exists, writable, and has real space.
 *
 * @param dir           Absolute path (e.g. "/mnt/sdcard")
 * @param resolved_dir  If non-NULL and success, returns same path
 * @return true if writable; false otherwise
 */
bool DUMPERUTILS_is_mount_ready(const char *dir, char *resolved_dir);

/**
 * Extract directory from path.
 * e.g., "/mnt/sdcard/foo/bar.raw" → "/mnt/sdcard/foo".
 * If no '/', output ".".
 */
void DUMPERUTILS_extract_dir(const char *path, char *dir_out, size_t size);

/**
 * Build fallback path by replacing mount-point prefix with DUMPER_FALLBACK_DIR.
 * e.g., "/mnt/sdcard/xxx" → "/tmp/xxx".
 * If prefix not matched, copy path unchanged.
 */
void DUMPERUTILS_build_fallback_path(const char *original_path, char *fallback_out, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* DUMPER_UTILS_H */
