#pragma once

enum class ResourceFileSystem {
    InUserPackage,
    InAppPackage,
    RawPath,
    RawPersistent,
    InSettingDir,
    InServerPackage,
    InDataDir,
    InUserDir,
    InExternalDir,
    InWorldDir,
    StoreCache
};