#include<iostream>
#include<string>

class HasNameAndID       
{
    public:
        HasNameAndID() = delete;
        HasNameAndID(std::string set_name, int set_id);
        virtual ~HasNameAndID() {};
        // When deleting a pointer to a subclass object, only the
        // destructor of the parent class is called. I searched
        // this bug and fixed it by stating a virtual destructor.
        const std::string& GetName() const;
        int GetID() const;

    protected:
        std::string name;
        int id;
};

HasNameAndID::HasNameAndID(std::string set_name,
    int set_id) : name(set_name), id(set_id) {}

const std::string& HasNameAndID::GetName() const
{
    return name;
}

int HasNameAndID::GetID() const
{
    return id;
}

class Prof : public HasNameAndID
{
    public:
        enum Rank {asst_prof, assoc_prof, full_prof};
        Prof() = delete;
        Prof(std::string set_name, int set_id, Rank r);
        Rank GetRank() const;

    private:
        Rank prof_rank;
};

Prof::Prof(std::string set_name, int set_id, Rank r)
    : HasNameAndID(set_name, set_id), prof_rank(r) {}

Prof::Rank Prof::GetRank() const
{
    return prof_rank;
}

class Undergrad : public HasNameAndID
{
    public:
        enum YearOfStudy {year_one, year_two, year_three,
            year_four};
        Undergrad() = delete;
        Undergrad(std::string set_name, int set_id, YearOfStudy y);
        YearOfStudy GetYearOfStudy() const;
    
    private:
        YearOfStudy undergrad_year;
};

Undergrad::Undergrad(std::string set_name, int set_id, YearOfStudy y)
    : HasNameAndID(set_name, set_id), undergrad_year(y) {}

Undergrad::YearOfStudy Undergrad::GetYearOfStudy() const
{
    return undergrad_year;
}

class Grad : public HasNameAndID
{
    public:
        Grad() = delete;
        Grad(std::string set_name, int set_id, int set_sup_id);
        int GetSupID() const;
    
    private:
        int sup_id;
};

Grad::Grad(std::string set_name, int set_id, int set_sup_id)
    : HasNameAndID(set_name, set_id), sup_id(set_sup_id) {}

int Grad::GetSupID() const
{
    return sup_id;
}

int main(int argc, char const *argv[])
{
    Prof test_prof("Bob", 123, Prof::Rank::asst_prof);
    std::cout << test_prof.GetRank() << '\n';
#if 1
	std::cerr << "Starting test code\n";
	// MDADAMS: Your class HasNameAndID has a critical bug.
	// MDADAMS: What if I wrote code like this?
	HasNameAndID* prof = new Prof("Bob", 123, Prof::Rank::asst_prof);
	delete prof;
	// What code is invoked in this case for destruction?
	// What code should be invoked in this case?
	// Use a source level debugger to trace through this delete operation.
	// What is called?
	// What should be called?
	std::cerr << "Ending test code\n";
#endif
    return 0;
}   