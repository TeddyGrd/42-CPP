/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:55 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 15:49:39 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main() {
    try {
        // Création d'un intern
        Intern intern;

        // Création de bureaucrates
        Bureaucrat highLevel("HighLevel", 1); // Peut tout signer et exécuter
        Bureaucrat midLevel("MidLevel", 72); // Peut signer mais pas tout exécuter
        Bureaucrat lowLevel("LowLevel", 150); // Ne peut rien faire

        // Création de formulaires
        std::cout << "-------- Form Creation --------" << std::endl;

        AForm* shrubbery = intern.makeForm("shrubbery creation", "Garden");
        AForm* robotomy = intern.makeForm("robotomy request", "Bender");
        AForm* pardon = intern.makeForm("presidential pardon", "Fry");

        std::cout << "-------- Signing Forms --------" << std::endl;

        // Tests de signature
        if (shrubbery) midLevel.signForm(*shrubbery); // Réussi
        if (robotomy) midLevel.signForm(*robotomy);   // Réussi
        if (pardon) lowLevel.signForm(*pardon);       // Échec

        std::cout << "-------- Executing Forms --------" << std::endl;

        // Tests d'exécution avec des grades différents
        if (shrubbery) {
            lowLevel.executeForm(*shrubbery);   // Échec
            midLevel.executeForm(*shrubbery);  // Réussi
        }

        if (robotomy) {
            lowLevel.executeForm(*robotomy);   // Échec
            midLevel.executeForm(*robotomy);   // Échec
            highLevel.executeForm(*robotomy);  // Succès ou échec (50%)
        }

        if (pardon) {
            midLevel.executeForm(*pardon);     // Échec
            highLevel.executeForm(*pardon);    // Réussi
        }

        std::cout << "-------- Final State --------" << std::endl;

        // Affichage des formulaires après les tests
        if (shrubbery) std::cout << *shrubbery << std::endl;
        if (robotomy) std::cout << *robotomy << std::endl;
        if (pardon) std::cout << *pardon << std::endl;

        std::cout << "-------- Cleaning Up --------" << std::endl;

        // Libération de mémoire
        delete shrubbery;
        delete robotomy;
        delete pardon;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}