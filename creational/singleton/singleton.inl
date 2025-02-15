// ========== Globals ==========
inline int Globals::GetSystemState() {
    return this->systemState;
}

inline int Globals::GetNumberOfFiles() {
    return this->numberOfFiles;
}

inline void Globals::SetSystemState(int systemState) {
    this->systemState = systemState;
}

inline void Globals::SetNumberOfFiles(int numberOfFiles) {
    this->numberOfFiles = numberOfFiles;
}