get_filename_component(UNIC_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(UNIC_INCLUDE_DIRS "${UNIC_CMAKE_DIR}/../include")
set(UNIC_LIBRARY_DIR "${UNIC_CMAKE_DIR}/../lib")
set(UNIC_LIBRARIES "${UNIC_LIBRARY_DIR}/unic.a")