//#include <random>
//#include <string>
//#include <set>
//#include "Multiset.h"
//
//   MultiSet::MultiSet() {
//        ContainerMultiSet = multiset<int>();
//    }
//
//    bool MultiSet::emptySetList() {
//        return ContainerMultiSet.empty();
//    }
//
//    bool MultiSet::elemInSetList(int values) {
//        return ContainerMultiSet.contains(values);
//    }
//
//    bool MultiSet::addelem(int values)
//    {
//        ContainerMultiSet.insert(values);
//
//        // Проверяем, что элемент был добавлен успешно
//        if (ContainerMultiSet.count(values) > 0) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//
//    MultiSet::MultiSet(int len, int min, int max, char setType){
//        if (min > max || len <= 0 || max - min < len) {
//            return;
//        }
//        while (len > 0) {
//            bool check = addelem(random(min, max));
//            if (check) {
//                len--;
//            }
//        }
//    }
//
//    int MultiSet::Power_SetList() {
//        return ContainerMultiSet.size();
//    }
//
//    string MultiSet::toString(char sym) {
//        if (!emptySetList()) {
//            std::string result = "";
//            for (int i = 0; i < ContainerMultiSet.size(); i++) {
//                if (ContainerMultiSet[i]) {
//                    result += std::to_string(i);
//                    result += sym;
//                }
//            }
//            return result.substr(0, result.length() - 1);
//        }
//        return "";
//    }
//
//    MultiSet::~MultiSet() {}
//
//    bool MultiSet::isSubset(MultiSet* sub_set) {
//        return (ContainerMultiSet & sub_set->ContainerMultiSet) == ContainerMultiSet;
//    }
//
//    bool MultiSet::equalSet(MultiSet* set_B) {
//        return ContainerMultiSet == set_B->ContainerMultiSet;
//    }
//
//    MultiSet* MultiSet::unitySet(MultiSet& anotherSet) {
//        MultiSet* set_C = new MultiSet();
//        set_C->ContainerMultiSet = ContainerMultiSet | anotherSet.ContainerMultiSet;
//        return set_C;
//    }
//
//    MultiSet* MultiSet::intersectionSet(MultiSet& anotherSet) {
//        MultiSet* set_C = new MultiSet();
//        set_C->ContainerMultiSet = ContainerMultiSet & anotherSet.ContainerMultiSet;
//        return set_C;
//    }
//
//    MultiSet* MultiSet::differenceSet(MultiSet& anotherSet) {
//        MultiSet* set_C = new MultiSet();
//        set_C->ContainerMultiSet = ContainerMultiSet & ~(anotherSet.ContainerMultiSet);
//        return set_C;
//    }
//
//    MultiSet* MultiSet::symmetrydifferentSet(MultiSet& anotherSet) {
//        MultiSet* unitySets = unitySet(anotherSet);
//        MultiSet* intersectionSets = intersectionSet(anotherSet);
//        return unitySets->differenceSet(anotherSet);
//    }
//
//    int MultiSet::random(int min, int max) {
//        random_device rd;
//        mt19937 gen(rd());
//        uniform_int_distribution<> dist(min, max);
//        return dist(gen);
//    }