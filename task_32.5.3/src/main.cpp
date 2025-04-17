#include <iostream>
#include <cassert>
#include "company.pb.h"

int main() {
    Company src_comp;
    assert(!src_comp.IsInitialized());
    src_comp.set_foundation_year(2025);
    src_comp.set_legal_address("Bogorodsk, Nizhny Novgorod region");
    src_comp.set_name("GreatCompany");
    assert(src_comp.IsInitialized());
    src_comp.set_type_of_activity("Engineers");
    src_comp.set_foreign_economic_activity(true);
    std::string serialized_comp = src_comp.SerializeAsString();

    Company dst_comp;
    assert(!dst_comp.IsInitialized());
    dst_comp.ParseFromString(serialized_comp);
    assert(dst_comp.IsInitialized());
    std::cout << "Company: " << std::endl << dst_comp.DebugString();

    return EXIT_SUCCESS;
}
